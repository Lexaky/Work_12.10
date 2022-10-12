#include <iostream>

using namespace std;

int main()
{
    //������� �� ������� ��������� �����. ���������� ��������� ����������� ����� ���.
    setlocale(LC_ALL, "rus");

    const int N = 128;
    int stringCounts = 16; //Max counts of strings (Or enter <enter>)
    char **arr_str = new char* [N];
    char *str = new char[N];
    for (int i = 0; i <= N-1; i++)
    {
        arr_str[i] = new char[N];
    }

    int i = 0;
    int countsPalindromes = 0;
    while (i < stringCounts)
    {
        cout << "Enter string: ";
        gets(arr_str[i]);
        if (!((int)arr_str[i][0] >= 32 && (int)arr_str[i][0] <= 126)) break;
        i++;
    }

    int l, countsSpace, u;
    bool flag;
    //�������� �� ����������
    for(int j = 0; j < i; j++)
    {
        l = 0;
        countsSpace = 0;
        //����� ���������� �������� � ������ (��������� � ���������� l)
        while (l <= N && (int)arr_str[j][l] >= 32 && (int)arr_str[j][l] <= 126)
        {
            l++;
        }

        for (int k = 0; k < l; k++)
        { //��� ����� � ������ �������
            if ((int)arr_str[j][k] >= 65 && (int)arr_str[j][k] <= 90)
            {
                arr_str[j][k] = char((int)arr_str[j][k] + 32);
            }
        }
        u = 0;

        for (int k = 0; k < l; k++) //������ �������
        {
            if ((int)arr_str[j][k] != 32)  {str[u] = arr_str[j][k]; u++;}
            else countsSpace++;
        }
        arr_str[j] = str;
        l -= countsSpace; //�������� ����� ����� ��� ��������
        flag = true;
        for (int k = 0; k <= l / 2; k++)
        {
            if (arr_str[j][k] != arr_str[j][l-k-1]) {flag = false; break;}
        }
        if (flag == true) countsPalindromes++; //cout << "���������: " << arr_str[j] << endl;
    }
    cout << "Found " << countsPalindromes << " palindromes" << endl;
    for (int i = 0; i <= N-1; i++)
    {
        delete arr_str[i];
    }
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
