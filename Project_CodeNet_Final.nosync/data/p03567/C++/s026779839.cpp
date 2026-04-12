#include <bits/stdc++.h>
using namespace std;
string str;
void solve()
{
    int i,len=str.length(),tag=0;
    for (i=1;i<len;i++)
        if (str[i-1]=='A'&&str[i]=='C') {tag=1;break;}
    if (tag) cout<<"Yes";
    else cout<<"No";
    cout<<endl;
}
int main()
{
    while(cin>>str)
        solve();
}