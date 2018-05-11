#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    qint8 choosed_radio_langge=0;
    qint8 last_choosed_radio_langge=0;
    qint8 choosed_radio_ifPro=0;
    qint8 last_choosed_radio_ifPro=0;
    qint8 last_Pro_typ=0;
    //qint8 choosed_radio_usewhattransl=0;
    QString text_in;
    QString text_out;
    Dialog dialog2;
private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_copy_clicked();

    //void on_edit_in_textChanged();

    void on_textEdit_in_textChanged();
    QString gszl(QString strin1);
    QString QtoB(QString strin1);
    QString BtoQ(QString strin1);
    void on_radioButton_in_eng_clicked();

    void on_radioButton_in_chin_clicked();

    void on_pushButton_clear_clicked();

    void on_radioButton_zl_clicked();

    void on_radioButton_transla_clicked();

    void on_radioButton_in_chin_eng_clicked();

    void on_textEdit_out_textChanged();

    void on_pushButton_magic_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
