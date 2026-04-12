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
   vector<int>h(n);
   int ans=0,mx=0;
    for (int i = 0; i < n; ++i) {
        cin >>h[i];
        if(h[i]>=mx){
            ans++;
            mx=h[i];
        }
    }
    cout <<ans <<endl;
}
