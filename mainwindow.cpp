#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QClipboard>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Copyright@libo_go@163.com 仅供交流学习");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ok_clicked()
{
   int Pro_typ=0;
   last_choosed_radio_ifPro=choosed_radio_ifPro;

  if(choosed_radio_ifPro==0)//choosed_radio_langge==0)
  { 
      text_out=gszl(text_in);
      ui->textEdit_out->setPlainText(text_out);
      QString stemp1=QString("输入%1，输出%2 仅整理").arg(text_in.length()).arg(text_out.length());
      ui->statusBar->showMessage(stemp1);
  }
  else if(choosed_radio_ifPro==1)
  {
      Pro_typ=ui->comboBox_trans_type->currentIndex();
      last_Pro_typ=Pro_typ;
      if(Pro_typ==0)
      {
          QString text_out_temp=gszl(text_in);
          text_out_temp.replace(" a"," A").replace(" b"," B").replace(" c"," C").replace(" d"," D").replace(" e"," E").replace(" f"," F");
          text_out_temp.replace(" g"," G").replace(" h"," H").replace(" i"," I").replace(" j"," J").replace(" k"," K").replace(" l"," L").replace(" m"," M");
          text_out_temp.replace(" n"," N").replace(" o"," O").replace(" p"," P").replace(" q"," Q").replace(" r"," R").replace(" s"," S").replace(" t"," T");
          text_out_temp.replace(" u"," U").replace(" v"," V").replace(" w"," W").replace(" x"," X").replace(" y"," Y").replace(" z"," Z");

          text_out_temp.replace("-a","-A").replace("-b","-B").replace("-c","-C").replace("-d","-D").replace("-e","-E").replace("-f","-F");
          text_out_temp.replace("-g","-G").replace("-h","-H").replace("-i","-I").replace("-j","-J").replace("-k","-K").replace("-l","-L").replace("-m","-M");
          text_out_temp.replace("-n","-N").replace("-o","-O").replace("-p","-P").replace("-q","-Q").replace("-r","-R").replace("-s","-S").replace("-t","-T");
          text_out_temp.replace("-u","-U").replace("-v","-V").replace("-w","-W").replace("-x","-X").replace("-y","-Y").replace("-z","-Z");
          QChar tempat0=text_out_temp.at(0);
          text_out_temp.replace(0,1,tempat0.toUpper());
          text_out=text_out_temp;
          ui->textEdit_out->setPlainText(text_out);
          QString stemp1=QString("输入%1，输出%2 单词首字母转大写").arg(text_in.length()).arg(text_out.length());
          ui->statusBar->showMessage(stemp1);
      }
      else if(Pro_typ==1)
      {
          QString text_out_temp=gszl(text_in);
          text_out=text_out_temp.toLower();
          ui->textEdit_out->setPlainText(text_out);
          QString stemp1=QString("输入%1，输出%2 大写字母转小写").arg(text_in.length()).arg(text_out.length());
          ui->statusBar->showMessage(stemp1);
      }
      else if(Pro_typ==2)
      {
          QString text_out_temp=gszl(text_in);
          text_out=text_out_temp.toUpper();
          ui->textEdit_out->setPlainText(text_out);
          QString stemp1=QString("输入%1，输出%2 小写字母转大写").arg(text_in.length()).arg(text_out.length());
          ui->statusBar->showMessage(stemp1);
      }
      else if(Pro_typ==3)
      {
          QString text_out_temp=gszl(text_in);
          text_out=QtoB(text_out_temp);
          ui->textEdit_out->setPlainText(text_out);
          QString stemp1=QString("输入%1，输出%2 全角字符转半角").arg(text_in.length()).arg(text_out.length());
          ui->statusBar->showMessage(stemp1);
      }
      else if(Pro_typ==4)
      {
          QString text_out_temp=gszl(text_in);
          text_out=BtoQ(text_out_temp);
          ui->textEdit_out->setPlainText(text_out);
          QString stemp1=QString("输入%1，输出%2 半角字符转全角").arg(text_in.length()).arg(text_out.length());
          ui->statusBar->showMessage(stemp1);
      }
      else if(Pro_typ==5)
      {
          dialog2.show();
      }

  }


}

void MainWindow::on_pushButton_copy_clicked()
{
    QString tempresult=ui->textEdit_out->toPlainText();
    QClipboard *board = QApplication::clipboard();
    board->setText(tempresult);
    ui->statusBar->showMessage("结果已复制到剪切板！");
}

void MainWindow::on_pushButton_magic_clicked()
{
    QClipboard *board = QApplication::clipboard();
    QString text_in_temp=board->text();
    qint8 Pro_typ1=ui->comboBox_trans_type->currentIndex();

    if(text_in_temp!=text_out)
    {
            text_in=text_in_temp;
            ui->textEdit_in->setPlainText(text_in);
            on_pushButton_ok_clicked();
            on_pushButton_copy_clicked();
    }
    else if(text_in_temp==text_out)
    {
        if(last_choosed_radio_ifPro!=choosed_radio_ifPro||last_choosed_radio_langge!=choosed_radio_langge||last_Pro_typ!=Pro_typ1)
        {
            ui->textEdit_in->setPlainText(text_in);
            on_pushButton_ok_clicked();
            on_pushButton_copy_clicked();
        }

    }

}


void MainWindow::on_textEdit_in_textChanged()
{
    text_in=ui->textEdit_in->toPlainText();
}

void MainWindow::on_textEdit_out_textChanged()
{
    //text_out=ui->textEdit_out->toPlainText();
}

QString MainWindow::gszl(QString strin1)
{
    QString strtemp1=strin1;
    last_choosed_radio_langge=choosed_radio_langge;
    if(choosed_radio_langge==0)  //english
    {
        strtemp1.replace("-\r\n-","").replace("-\n\r-","").replace("-\n-","").replace("-\r-","");
        strtemp1.replace("-\r\n","").replace("-\n\r","").replace("-\n","").replace("-\r","");
        strtemp1.replace("\r\n"," ").replace("\n\r"," ").replace("\n"," ").replace("\r"," ");
        for(int i=1;i<20;i++)
        {
         strtemp1.replace("  "," ");
        }

    }
    else if(choosed_radio_langge==1)   //chinese
    {
       strtemp1.replace("\r\n","").replace("\n\r","").replace("\n","").replace("\r","");
       for(int i=1;i<20;i++)
       {
        strtemp1.replace(" ","");
       }

    }
    else if(choosed_radio_langge==2) //zhongyingwen
    {
        strtemp1.replace("-\r\n","").replace("-\n\r","").replace("-\n","").replace("-\r","");
        strtemp1.replace("\r\n","").replace("\n\r","").replace("\n","").replace("\r","");
        for(int i=1;i<20;i++)
        {
         strtemp1.replace("  "," ");
        }

    }
    return strtemp1;
}

QString MainWindow::QtoB(QString strin1)
{
       QString strin2=strin1;
       strin2.replace("ａ","a").replace("ｂ","b").replace("ｃ","c").replace("ｄ","d").replace("ｅ","e").replace("ｆ","f").replace("ｇ","g");
       strin2.replace("ｈ","h").replace("ｉ","i").replace("ｊ","j").replace("ｋ","k").replace("ｌ","l").replace("ｍ","m").replace("ｎ","n");
       strin2.replace("ｏ","o").replace("ｐ","p").replace("ｑ","q").replace("ｒ","r").replace("ｓ","s").replace("ｔ","t").replace("ｕ","u");
       strin2.replace("ｖ","v").replace("ｗ","w").replace("ｘ","x").replace("ｙ","y").replace("ｚ","z");

       strin2.replace("１","1").replace("２","2").replace("３","3").replace("４","4").replace("５","5").replace("６","6").replace("７","7");
       strin2.replace("８","8").replace("９","9").replace("０","0").replace("［","[").replace("］","]").replace("（","(").replace("）",")");
       //strin2.replace("，",",").replace("．",".").replace("；",";").replace("：",":").replace("＜","<").replace("＞",">");
       return strin2;
}

QString MainWindow::BtoQ(QString strin1)
{
    QString strin2=strin1;
    strin2.replace("a","ａ").replace("b","ｂ").replace("c","ｃ").replace("d","ｄ").replace("e","ｅ").replace("f","ｆ").replace("g","ｇ");
    strin2.replace("h","ｈ").replace("i","ｉ").replace("j","ｊ").replace("k","ｋ").replace("l","ｌ").replace("m","ｍ").replace("n","ｎ");
    strin2.replace("o","ｏ").replace("p","ｐ").replace("q","ｑ").replace("r","ｒ").replace("s","ｓ").replace("t","ｔ").replace("u","ｕ");
    strin2.replace("v","ｖ").replace("w","ｗ").replace("x","ｘ").replace("y","ｙ").replace("z","ｚ");

    strin2.replace("1","１").replace("2","２").replace("3","３").replace("4","４").replace("5","５").replace("6","６").replace("7","７");
    strin2.replace("8","８").replace("9","９").replace("0","０").replace("[","［").replace("]","］").replace("(","（").replace(")","）");
   // strin2.replace(",","，").replace(".","．").replace(";","；").replace(":","：").replace("<","＜").replace(">","＞");
    return strin2;
}



void MainWindow::on_radioButton_in_eng_clicked()
{
    choosed_radio_langge=0;
}
void MainWindow::on_radioButton_in_chin_clicked()
{
    choosed_radio_langge=1;
}
void MainWindow::on_radioButton_in_chin_eng_clicked()
{
    choosed_radio_langge=2;
}

void MainWindow::on_radioButton_zl_clicked()
{
    choosed_radio_ifPro=0;
    ui->comboBox_trans_type->setEnabled(false);
}

void MainWindow::on_radioButton_transla_clicked()
{
    choosed_radio_ifPro=1;
    ui->comboBox_trans_type->setEnabled(true);
}

void MainWindow::on_pushButton_clear_clicked()
{
    QString temp2="";
    text_in=temp2;
    text_out=temp2;
    ui->textEdit_in->setPlainText(text_in);
    ui->textEdit_out->setPlainText(text_out);
    ui->statusBar->showMessage("已清空");
}


