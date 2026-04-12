#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main(){
    int a,b,c,ans;
    string s,t,q;
    cin>>a>>b>>c;
    ans=a*100+b*10+c;
    if(ans%4==0) cout<<"YES\n";
    else cout<<"NO\n";
    return(0);
}