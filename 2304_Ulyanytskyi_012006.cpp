#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>

#elif __linux
#include <termios.h>
#endif

using namespace std;

void getInput(string& text, const string& chars)
{
#ifdef _WIN32
    system("CLS");
#elif __linux
    system("clear");
#endif

    char qt;
    cout << "��� ��������� �������� ����� �������� ������ esc\n";

#ifdef _WIN32
    while (true)
    {
        if (_kbhit()) {
            qt = _getch();
            for (int i = 0; i < chars.length(); i++) {
                if (qt == chars[i]) {
                    qt = ' ';
                }
                else if (qt == 13) {
                    qt = '\n';
                }
                else if (qt == 27) {
                    qt = ' ';
                    break;
                }
            }
            text += qt;
            cout << qt;
        }
    }
#elif __linux
    struct termios Old, New;
    bool run = true;
    tcgetattr(0, &Old);
    New = Old;
    New.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &New);

    while (run)
    {
        if (_kbhit())
        {
            qt = _getch();
            for (int i = 0; i < chars.length(); i++)
            {
                if (qt == chars[i])
                {
                    qt = ' ';
                }
                else if (qt == 13)
                {
                    qt = '\n';
                }
                else if (qt == 27)
                {
                    run = false;
                    qt = ' ';
                    break;
                }
            }
            text += qt;
            cout << qt;
        }
    }

    tcsetattr(0, TCSANOW, &Old);
#endif

    cout << endl << "�� ����� �����:\n";
    cout << text << endl;
}

int main()
{
    string ��� = "���������������������������������������������������������޴�������";
    string Eng = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM";
    string Num = "0123456789";
    string Symb = "`~!@#$%^&*()_+}{|\":<>?/.,\\';][=-�";
    string text;
    //char   qt;
    bool   menu_run = true;
    int    choice = 0;

#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#elif __linux
    struct termios Old, New;
#endif

    while (menu_run)
    {
        cout << "�������� 1 ��� ����� ���� ��������\n";
        cout << "�������� 2 ��� ����� ��������� ����� ��������\n";
        cout << "�������� 3 ��� ����� ���������� ���� ��������\n";
        cout << "�������� 4 ��� ����� ���������� ���� ��������\n";
        cin >> choice;

        switch (choice) {
        case 1:
            getInput(text, Num);
            break;
        case 2:
            getInput(text, Symb);
            break;
        case 3:
            getInput(text, Eng);
            break;
        case 4:
            getInput(text, ���);
            break;
        default:
            menu_run = false;
            break;
        }
    }

    return 0;
}