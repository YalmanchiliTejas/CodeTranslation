#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define pi 3.141592653589793
int nx[4]={0,-1,0,1};
int ny[4]={-1,0,1,0};

ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    ll r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main(){
    ll a,b,c,x,y;
    ll ans =1001001001001000100;
    ll zero=0;
    cin >> a >> b >> c >> x >> y;
    for(int i=0;i<=2*max(x,y);i++){
        if(i%2==1) continue;
        ll price=a*max(zero,x-i/2)+b*max(zero,y-i/2)+c*i;
        ans=min(ans,price);
    }
    cout << ans <<endl;

    return 0;
}
