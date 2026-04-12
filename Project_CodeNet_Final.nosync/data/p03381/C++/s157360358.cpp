#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<ll,ll> pint;

ll a[200001],b[200001];
int main(){
    int n;
    cin>>n;
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n);
    ll cur1=a[n/2-1],cur2=a[n/2];
    rep(i,n){
        if(b[i]>cur1){
            cout<<cur1<<endl;
        }
        else{
            cout<<cur2<<endl;
        }
    }
    return 0;
}