#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pl= pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
   int n;cin >>n;
   V a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    ll ans=0;
    sort(all(a));
    if(n%2==1){
        ll now=0;
        for (int i = 0; i < n / 2 - 1; ++i) {
            now-=a[i]*2;
        }
        for (int i =n/2-1; i <=n/2; ++i) {
            now-=a[i];
        }
        for (int i =n/2+1; i <n; ++i) {
            now+=a[i]*2;
        }
        ans=max(ans,now);
        now=0;
        reverse(all(a));
        for (int i = 0; i < n / 2 - 1; ++i) {
            now+=a[i]*2;
        }
        for (int i =n/2-1; i <=n/2; ++i) {
            now+=a[i];
        }
        for (int i =n/2+1; i <n; ++i) {
            now-=a[i]*2;
        }
        ans=max(ans,now);
        reverse(all(a));
    }
    else {
        ll now=0;
        for (int i = 0; i < n / 2 - 1; ++i) {
            now-=a[i]*2;
        }
        now-=a[n/2-1];
        now+=a[n/2];
        for (int i =n/2+1; i <n; ++i) {
            now+=a[i]*2;
        }
        ans=max(ans,now);
    }
    cout <<ans <<endl;
}
