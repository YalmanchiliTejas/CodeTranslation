#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin>>s;
    int cnt1=0,cnt2=0;
    for(int i=0;i<3;i++){
        if(s[i]=='A') cnt1++;
        else cnt2++;
    }
    if(cnt1==2||cnt2==2) cout<<"Yes";
    else cout<<"No";
    return 0;
}