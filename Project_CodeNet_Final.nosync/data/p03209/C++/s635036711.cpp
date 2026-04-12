#include<bits/stdc++.h>
#define INFTY 10000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const int MOD=1000000007;
const int di[4] = {-1,0,1,0};
const int dj[4] = {0,-1,0,1};
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

void cnt(ll x,int n,ll pt){
    //cout<<" "<<x<<" "<<n<<" "<<pt<<endl;
    ll a = pow(2,n+2)-3,b = pow(2,n+1)-1; 
    if(x==1) {cout<<pt <<endl;return;}
    if(x==a) {cout<<pt + b;return;}
    if(x==a/2+1){cout<< pt+b/2+1;return;}

    if(n>1){
        if(x>a/2+1&&x>1){
            cnt(x-(a/2+1),n-1,pt+b/2+1);
        }
        if(x<a/2+1&&x>1){
            cnt(x-1,n-1,pt);
        }
    }
    else{ 
        cout<<pt+x-1<<endl;
        return;
    }
}


int main(){
    int n; cin>>n;
    ll x;cin>>x;
    cnt(x,n,0);
    return 0;
}