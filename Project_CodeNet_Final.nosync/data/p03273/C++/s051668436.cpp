#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;

int main(void)
{
    int h,w,line[110],row[110];
    string a[110];
    cin >> h >> w;
    for(int i = 0;i < h;i++){cin >> a[i]; line[i] = 0;}
    for(int i = 0;i < w;i++){row[i] = 0;}
    for(int i = 0;i < h;i++)
    {
        bool judge = true;
        for(int j = 0;j < w;j++)
        {
            if(a[i][j] == '#'){judge = false; break;}
        }
        if(judge){line[i] = 1;}
    }
    for(int i = 0;i < w;i++)
    {
        bool judge = true;
        for(int j = 0;j < h;j++)
        {
            if(a[j][i] == '#'){judge = false; break;}
        }
        if(judge){row[i] = 1;}
    }
    for(int i = 0;i < h;i++)
    {
        bool judge = false;
        for(int j = 0;j < w;j++)
        {
            if(line[i] == 0 && row[j] == 0){cout << a[i][j]; judge = true;}
        }
        if(judge){cout << endl;}
    }
    return 0;
}