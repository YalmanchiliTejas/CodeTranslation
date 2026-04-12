#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
const long long LINF=1e18;
template<typename T>
void chmin(T &a,T b){
  if(a>b)a=b;
}
template<typename T>
void chmax(T &a,T b){
  if(a<b)a=b;
}

signed main(){
  int n;cin>>n;
  vector<P> b(n);
  int mx=0;
  for(int i=0;i<n;i++){
    int x,y;cin>>x>>y;
    if(x>y)swap(x,y);
    chmax(mx,y);
    b[i]=P(x,y);
  }
  sort(b.begin(),b.end());
  int ans=LINF;
  int A=b[n-1].first-b[0].first;
  int B=LINF;
  for(int i=0;i<n;i++)chmin(B,b[i].second);
  chmin(ans,A*(mx-B));
  map<int,int> m;
  for(int i=0;i<n;i++)m[b[i].first]++;
  for(int i=0;i<n;i++){
    chmin(ans,(mx-b[0].first)*(m.rbegin()->first-m.begin()->first));
    m[b[i].second]++;
    if(--m[b[i].first]==0)m.erase(b[i].first);
  }
  chmin(ans,(mx-b[0].first)*(m.rbegin()->first-m.begin()->first));
  cout<<ans<<endl;
}

/*
解説AC
一番小さいやつが赤のminとしていいまでは思いついたのにね
一番大きいやつも同様に注目して場合分けするだけだった
これ思いつかないのは流石にダメだね
minとmaxが同じ色の時のそれの正当性は？
とにかく青の間を小さくしたくて、途中まで赤そこから先青、じゃない時を考えると
途中で寝返ったやつよりあとのやつはどう考えてもそいつのそれからそうなので
全部を使った最小最大問題は必ず端になるものがそれぞれ見つかるのでそれらの関係性で場合分けするとシンプルになるぞい
*/
