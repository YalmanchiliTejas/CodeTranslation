#include <bits/stdc++.h>
using namespace std;


#define fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using lli = long long int;
using ll = long long ;
using ld=long double;
using d= double;

bool isPrime(ll n){if(n<2)return false;for(ll i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}

ll lcm(ll x,ll y){
    return (x*y)/(__gcd(x,y));
}

int sm(ll n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int fact(ll n){
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}

signed main(){
    fast_IO;
    int t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n>=30)
            cout<<"Yes";
        else
            cout<<"No";
    }   
    return 0;
}
