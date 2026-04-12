/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n,i,j,k,x,y,ans,temp,curr,m;
    int tc;
    string s;
    cin >> s;
    ans = 0;
    for(i=0;i<3;i++) if(s[i] == 'A') ans++;
    if(ans == 0 || ans == 3) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}
