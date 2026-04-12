#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

vector<ll> a(1,1),p(1,1);

void f(ll n){
    //cout << "e" << endl;
    for(int i=0;i<n;i++){
        a.push_back(a[i] * 2 + 3);
        p.push_back(p[i] * 2 + 1); 
    }
    //cout << "e1" << endl;
    return ;
}

ll func(ll n,ll x){
    //cout << "error" << endl;
    if(x==1){
        //cout << "e0" << endl;
        if(n==0) return 1;
        return 0;
    }else if(1<x && x<=1+a[n-1]){
        //cout << "e1" << endl;
        return func(n-1,x-1);
    }else if(x==2+a[n-1]){
        //cout << "e2" << endl;
        return p[n-1] + 1;
    }else if(2+a[n-1]<x && x<=2+2*a[n-1]){
        //cout << "e3" << endl;
        return p[n-1] + 1 + func(n-1,x-2-a[n-1]);
    }else if(x==3+2*a[n-1]){
        //cout << "e4" << endl;
        return 2*p[n-1] + 1;
    }
}

int main(){
    ll n,x;cin>>n>>x;
    f(n);
    cout << func(n,x) << endl;
}