#include<iostream>
using namespace std;
typedef long long ll;
ll p[51];
ll a[51];

ll f(ll n,ll k){
    //cout << "n=" << n << "k=" << k << endl;
    if(k == 1){
        if(n == 0){
            return 1;
        }
        else{
            return 0;
        }
        
    }
    else if(1 < k && k <= a[n-1] + 1){
        return f(n-1,k-1);
    }
    else if(k == a[n-1] + 2){
        return p[n-1] + 1;
    }
    else if(a[n-1] + 2 < k && k <= a[n-1] * 2 + 2){
        return p[n-1] + f(n-1,k-a[n-1]-2)+ 1;
    }
    else{
        return 2*p[n-1] + 1;
    }
}

int main(){
    ll n;ll k;cin >> n >> k;
    ll ans  = 0;
    p[0] = 1;
    a[0] = 1;
    for(int i=1;i<=50;i++){
        p[i] = p[i-1] * 2 + 1;
        //cout << p[i] << endl;
    }
    for(int i=1;i<=50;i++){
        a[i] = a[i-1] * 2 + 3;
        //cout << a[i] << endl;
    }
    ans = f(n,k);
    cout << ans << endl;
}