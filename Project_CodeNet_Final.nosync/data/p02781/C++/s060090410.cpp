#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

ll com(ll n,ll r){
    ll ret=1;
//    if(r<=0){
//        return 1;
//    }
    for (int i = 0; i < r; ++i) {
        ret*=n-i;
    }
    ll d=1;
    for (int i = 0; i < r; ++i) {
        d*=i+1;
    }
    return ret/d;
}

ll g(string n,ll i,ll k,ll ans){
    ll d=n.size()-i;
    ll f=n[i]-'0';
    if(k<=0){
        return ans;
    }
    if(f==0){
        if(i+1<n.size()) {
            return g(n, i + 1, k, ans);
        }
        else {
            return ans-1;
        }
    }
    ll tmp=com(d-1,k);
    for (int j = 0; j < k; ++j) {
        tmp*=9;
    }
    ans+=tmp;
//    cout <<ans <<endl;
    tmp=com(d-1,k-1);
//    cout <<tmp<<endl;
    for (int j = 0; j < k - 1; ++j) {
        tmp*=9;
    }
//    cout <<f<<endl;
    ans+=tmp*(f-1);
//    cout <<ans <<endl;
    if(i+1<n.size()) {
        return g(n, i + 1, k - 1, ans);
    }
    else {
        return ans;
    }
}

int main(){
    string n;cin >>n;
    ll k;cin >>k;
    if(n.size()<k){
        cout <<0<<endl;
    }
    else {
        cout << g(n, 0, k, 0) + 1 << endl;
    }
    return 0;
}

