#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main(){
    cs;
    int a,b,x,t=1;
    cin>>x>>a;
    rep(i,x-1){
        cin>>b;
        if(b>=a) t++;
        a=max(a,b);
    }
    cout<<t;
}