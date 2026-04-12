#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

ll a[51];
int main(){
    int n;
    cin>>n;
    rep(i,n) cin>>a[i];
    ll cnt=0;
    while(1){
        ll sum=0;
        bool flag=true;
        rep(i,n) sum+=a[i]/n;
        cnt+=sum;
        rep(i,n){
            a[i]+=sum-a[i]/n-a[i]/n*n;
            if(a[i]>=n) flag=false;
        }
        if(flag) break;
    }
    cout<<cnt<<endl;
    return 0;
}