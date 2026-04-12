#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
string s;
ll k,dp[110][4][2];


ll Rec(int i , int k , bool isSmaller){

    if(k < 0)   return 0;
    if(i == s.size())  return (k == 0);

    if(dp[i][k][isSmaller] != -1)  return dp[i][k][isSmaller];

    ll Res = 0;

    for(char j = '0';j<='9';j++){
        if(j <= s[i] || isSmaller) Res+=Rec(i + 1 , j == '0' ? k : k - 1 , j < s[i] ? true : isSmaller);
    }

    return dp[i][k][isSmaller] = Res;
}

int main()
{
    memset(dp , -1 , sizeof(dp));
    cin >> s >> k;
    cout << Rec(0 , k , 0);
    return 0;
}
