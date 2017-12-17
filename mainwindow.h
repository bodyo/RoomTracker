#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QListWidget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setUpUi();

    void addItemToBuy(QString &itemName, QListWidget *listWidget);

private slots:
    void showMainTextInputDialog();
    void showShopListTextInputDialog();
    void showToDoTextInputDialog();


private:
    QString showInputDialog(const QString &title, const QString &label);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
