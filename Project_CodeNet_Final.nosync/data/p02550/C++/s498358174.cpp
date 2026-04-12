#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  ll n;
  int x, m;
  cin >> n >> x >> m;
  vector<int> vec(m);
  vector<int> cycle;
  int pre, next=x;
  ll sum=0;
  bool flag=false;
  int ind;
  repo(i, m){
    if(vec[next]!=0){
      ind=vec[next]-1;
      break;
    }
    if(next==0){
      flag=true;
      break;
    }
    vec[next]=i;
    cycle.push_back(next);
    sum+=next;
    pre=next;
    next=(int)(((ll)next*next)%m);
  }
  int num=cycle.size()-ind;
  rep(i,ind){
    sum-=cycle[i];
  }
  ll ans=0;
  if(flag){
    ans+=sum;
  } else {
    rep(i,ind){
      ans+=cycle[i];

    }
    n-=ind;
    ans+=n/num*sum;
    int num2=n%num;
    for(int i=ind; i<ind+num2;i++){
      ans+=cycle[i];
    }
  }
  cout << ans << endl;
  return 0;
}
