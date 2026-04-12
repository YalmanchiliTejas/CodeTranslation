#include <bits/stdc++.h>
//↓✟MLE魔、TLE魔✟
#define int long long
//↑✟MLE魔、TLE魔✟
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
int gcd(int a,int b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
bool prime(int a){
    if(a==1)return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)return false;
    }
    return true;
}
signed main(){
    int h,w,cnt=0;
    cin>>h>>w;
    rep(i,h)
        rep(i,w){
            char c;
            cin>>c;
            if(c=='#')cnt++;
        };
    if(cnt==h+w-1)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}