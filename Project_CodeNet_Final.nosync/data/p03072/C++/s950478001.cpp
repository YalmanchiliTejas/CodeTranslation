#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
int h[110];

int main()
{
    int n;  cin >> n;
    for(int i = 0;i<n;i++)  cin >> h[i];
    int Ans =0 ;
    for(int i = 0;i<n;i++){
        bool ok = true;
        for(int j = i;j>=0;j--)  ok&=h[i]>=h[j];
        if(ok)  Ans++;
    }
    cout << Ans;
    return 0;
}
