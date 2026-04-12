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
    int n,k;
    char tmp;
    string s;
    cin >> n >> s >> k;
    tmp = s[k - 1];
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] != tmp){s[i] = '*';}
    }
    cout << s << endl;
    return 0;
}