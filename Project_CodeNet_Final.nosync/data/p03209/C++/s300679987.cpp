#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
typedef long long ll;
ll lv[51];
ll cntL(ll level){
  if(level == 0){
    lv[0] = 1;
    return 1;
  }
  if(lv[level] != 0) return lv[level] ;
  lv[level] = 3 + 2*cntL(level - 1);
  return lv[level];
}

ll pati(ll level,ll index){
  //cout << "cntL ," << level << ", "<< cntL(level) << endl;
  if(level == 0 && index == 0){
    return 1;
  }
  if(index == 0) return 0;//ban
  else if(index <= cntL(level-1)){
    //cout << "level =" << level << " index = "<< index << " pat " << 0 << endl;
    return pati(level-1,index-1);
  }else if(index == cntL(level-1) + 1){
    //cout << "level =" << level << " index = "<< index << " pat " << 1 << endl;
    return pati(level-1,cntL(level-1)-1) + 1;
  }else if(index < cntL(level) - 1){
    //cout << "level =" << level << " index = "<< index << " pat " << 2 << endl;
    return pati(level-1,cntL(level-1)-1) + 1 + pati(level - 1, index - cntL(level-1) - 2);
  }else if(index == cntL(level) - 1){
    //cout << "level =" << level << " index = "<< index << " pat " << 3 << endl;
    return 1+ 2*pati(level-1,cntL(level-1)-1);
  }
  cout << "error"<< endl;
  return 0;
}

int main(){
  ll n,x;
  cin >> n >> x;
  ll ans = pati(n,x-1);
  cout << ans << endl;
  return 0;
}
