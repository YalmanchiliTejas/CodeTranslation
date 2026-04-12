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
    int n,h[25],count = 1;
    cin >> n;
    for(int i = 0;i < n;i++){cin >> h[i];}
    for(int i = 1;i < n;i++)
    {
        bool judge = true;
        for(int j = i - 1;0 <= j;j--)
        {
            if(h[i] < h[j]){judge = false; break;}
        }
        if(judge){count++;}
    }
    cout << count << endl;
    return 0;
}