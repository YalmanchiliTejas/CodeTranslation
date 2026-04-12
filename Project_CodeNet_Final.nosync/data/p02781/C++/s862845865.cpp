#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  string N;
  int K;
  cin >> N >> K;
  int size=N.size();
  vi d(size);
  rep(i,size) d[i]=N[i]-'0';
  
  int ans=0,add;
  rep2(i,K,size) {
    add=9;
    rep(j,K-1) {
      add*=(i-1-j)*9;
      add/=(j+1);
    }
    ans+=add;
  }
  if(K<=size) {
    add=d[0]-1;
    rep(j,K-1) {
      add*=(size-1-j)*9;
      add/=(j+1);
    }
    ans+=add;
    if(K==1) ans+=1;
    else {
      int k=1;
      while(k<size) {
        if(d[k]!=0) break;
        k++;
      }
      if(K==2&&k<size) ans+=d[k]+9*(size-k-1);
      else if(K==3&&k<size-1) {
        ans+=(size-k-1)*(size-k-2)/2*81;
        int l=k+1;
        while(l<size) {
          if(d[l]!=0) break;
          l++;
        }
        if(l<size) ans+=(d[k]-1)*9*(size-k-1)+d[l]+9*(size-l-1);
      }
    }
  }
  
  cout << ans << endl;
}