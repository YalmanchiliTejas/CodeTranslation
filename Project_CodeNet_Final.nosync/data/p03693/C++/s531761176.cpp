#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
int main(void){
    int a,b,c;
    cin>>a>>b>>c;
    if((b*2+c)%4)cout<<"NO";
    else cout<<"YES";
    return 0;
}