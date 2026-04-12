#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> sa(n-1);
    ll x=1000000000;
    rep(i,n){
        cin >> a.at(i);
    }
    sa.at(0)=a.at(n-1);
    rep(i,n-2){
        sa.at(i+1)=(a.at(n-2-i)+sa.at(i))%(x+7);
    }
    reverse(sa.begin(),sa.end());
    ll sum=0;
    for(int i=0;i<n-1;i++){
        sum+=(a.at(i)*sa.at(i))%(x+7);
    }
    sum = sum % (x+7);
    cout << sum << endl;
}