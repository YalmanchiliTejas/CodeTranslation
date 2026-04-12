#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   int n;cin >>n;
   vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    sort(all(a));
    ll ans=0;
    if(n%2==1){
        ll now=0;
        for (int i = 0; i < n / 2 - 1; ++i) {
            now-=a[i]*2;
        }
        for (int i =n/2+2; i <n; ++i) {
            now+=a[i]*2;
        }
        now+=a[n/2+1];
        now-=a[n/2-1];
        ans=max(now+a[n/2]-a[n/2-1],now-a[n/2]+a[n/2+1]);
    }
    else {
        ll now=0;
        for (int i = 0; i < n / 2 - 1; ++i) {
            now-=a[i]*2;
        }
        now-=a[n/2-1];
        for (int i =n/2+1; i <n; ++i) {
            now+=a[i]*2;
        }
        now+=a[n/2];
        ans=max(ans,now);
    }
    cout <<ans <<endl;
}
