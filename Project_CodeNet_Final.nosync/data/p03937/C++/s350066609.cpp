#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
  int h,w;cin >>h>>w;
  vector<int>mx(h,-1);
  vector<int>mint(h,INF);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char a;cin >>a;
            if(a=='#'){
                mx[i]=max(mx[i],j);
                mint[i]=min(mint[i],j);
            }
        }
    }
    bool flg=true;
    for (int i = 0; i < h-1; ++i) {
        if(mx[i]>mint[i+1])flg=false;
        if(mint[i]==INF)flg=false;
    }
    if(flg)puts("Possible");
    else puts("Impossible");
  return 0;
}

