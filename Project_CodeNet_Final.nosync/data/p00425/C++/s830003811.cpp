#include <iostream>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>

using namespace std;

    int n=5;
    int w=4;
    int t=1;
    int tmp;

int go_r()
{ 
    tmp = n;
    n = w;
    w = 7-tmp;
    return t;
}
int go_l()
{
    tmp = w;
    w = n;
    n = 7-tmp;
    return t;
}
int go_n()
{
    tmp = n;
    n = t;
    t = 7-tmp;
    return t;
}
int go_e()
{
    tmp = t;
    t = w;
    w = 7-tmp;
    return t;
}
int go_w()
{
    tmp = w;
    w = t;
    t = 7-tmp;
    return t;
}
int go_s()
{
    tmp = t;
    t = n;
    n = 7-tmp;
    return t;
}

int main(int argc, char const* argv[])
{
    int row;
    while (cin >> row) 
    {
        int sum=1;
        n=5;
        w=4;
        t=1;
        //テァツオツづァツォツッテ・ツ按、テヲツ鳴ュ
        if (row==0){break;}
        string s;
        for (int i = 0; i < row; i++) 
        {
            cin >> s;
            if(s == "North"){ sum += go_n();}
            if(s == "South"){ sum += go_s();}
            if(s == "West") { sum += go_w();}
            if(s == "East") { sum += go_e();}
            if(s == "Right"){ sum += go_r();}
            if(s == "Left") { sum += go_l();}
        }
        cout << sum << endl;
    }
    return 0;
}