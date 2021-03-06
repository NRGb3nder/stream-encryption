#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QThread>
#include "types.h"
#include "implementation/workers/worker.h"
#include "implementation/workers/simplecryptworker.h"
#include "implementation/workers/geffeworker.h"
#include "implementation/workers/rc4worker.h"
#include "implementation/lfsrdata.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void workDone(QString sourceContent, QString resultContent, QString keyContent);

    void on_rbtnSimple_clicked();

    void on_rbtnGeffe_clicked();

    void on_rbtnRC4_clicked();

    void on_btnChooseInput_clicked();

    void on_btnChooseOutput_clicked();

    void on_btnExecute_clicked();

signals:
    void doWork();

private:
    Ui::MainWindow *ui;
    void setInputValidators();
    void enableSimpleStreamEncryptionMode(bool);
    void enableGeffeCipherMode(bool);
    void enableRC4Mode(bool);
    void displayError(ErrorType);
    void runSimpleStreamEncryptionMode(QString inputFileName, QString outputFileName);
    void runGeffeMode(QString inputFileName, QString outputFileName);
    void runRC4Mode(QString inputFileName, QString outputFileName);
    QThread *getWorkerThread(Worker *);
};

#endif // MAINWINDOW_H
