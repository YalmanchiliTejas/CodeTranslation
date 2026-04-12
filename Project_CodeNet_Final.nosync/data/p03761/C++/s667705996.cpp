#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  map<char, int> amap;
  string S;
  for(int i=0;i<N;++i) {
    cin>>S;
    map<char, int> bmap;
    for(int j=0;j<S.size();++j) {
      bmap[S[j]]++;
    }
    if(i==0) {
      for(char a='a';a<='z';++a) amap[a] = bmap[a];
    }
    else {
      for(char a='a';a<='z';++a) amap[a] = min(amap[a], bmap[a]);
    }
  }
  string ans;
  for(char a='a';a<='z';++a) {
    for(int i=0;i<amap[a];++i) ans.push_back(a);
  }
  cout<<ans<<endl;
}

