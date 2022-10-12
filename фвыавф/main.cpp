#include <iostream>

using namespace std;

int main()
{
    //������� �� ������� ��������� �����. ���������� ��������� ����������� ����� ���.
    setlocale(LC_ALL, "rus");
    const int N = 128;
    char **arr_str = new char* [N];
    for (int i = 0; i <= N-1; i++)
    {
        arr_str[i] = new char[N];
    }
    char inp[N];
    int i = 0;
    while (i < 4)
    {
        cout << "Enter string: ";
        cin >> arr_str[i];
        i++;
    }
    bool flag;
    for(int j = 0; j < 4; j++)
    {
        i = 0;
        while (i <= N && (int)arr_str[j][i] >= 32 && (int)arr_str[j][i] <= 126)
        {
            i++;
        }
        //� i ���������� �������� � ������.
        flag = true;
        for (int k = 0; k <= i / 2; k++)
        {
           // cout << arr_str[j][k] << " ";
            //cout << "Symbol: " << arr_str[j][k] << " ";
            //cout << arr_str[j][k] << " and " << arr_str[j][i-k-1] << endl;
            if (arr_str[j][k] != arr_str[j][i-k-1]) {flag = false; break;}
        }
        if (flag == true) cout << "���������: " << arr_str[j] << endl;
    }

    delete []arr_str;
    /*
    //������� free() - ��� ������� C
    //Malloc �������� ������ � �� ��������� �
    //Calloc �������� ������ � ��������� � ������
    int *x = (int*)malloc(sizeof(int));
    int b = 3;
    *x = b;
    cout << *x << endl; */
    return 0;
}
