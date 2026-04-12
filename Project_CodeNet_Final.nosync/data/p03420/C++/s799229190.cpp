#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using P = pair<ll,ll>;

int main(){
   ll n,k;cin >>n>>k;
   ll ans=0;

    for (int b =k+1; b <=n ; ++b) {
        ans+=(n/b)*(b-k);
        ans+=(n%b-k)>=0?(n%b-k+1):0;
        if(k==0)ans--;
    }
    cout <<ans <<endl;
    return 0;
}