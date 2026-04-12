#include<bits/stdc++.h>
using namespace std;
#define INS(x) x.begin(),x.end()
    
char s[256];
    
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    
    for (auto i:s)
        s[i]++;
    if (s['A']&&s['B']) cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}