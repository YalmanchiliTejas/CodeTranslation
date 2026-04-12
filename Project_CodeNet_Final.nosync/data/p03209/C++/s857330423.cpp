#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;
vector<ll> a, p;

ll f(ll N, ll X){
    if(N == 0){
        if(X<=0){
            return 0;
        }else{
            return 1;
        }
    }
    if(X <= 1+ a[N-1]){
        return f(N-1, X-1);
    }else{
        return p[N-1] + 1 + f(N-1, X-2-a[N-1]);
    }
}

int main(){
    ll n, x;
    ll tmp;
    cin >> n >> x;
    a.push_back(1);
    p.push_back(1);
    for(int i=0; i<n; i++){
        tmp = a[i]*2+3;
        a.push_back(tmp);
        tmp = p[i]*2+1;
        p.push_back(tmp);
    }
    tmp = f(n,x);
    cout << tmp << endl;
    return 0;
}