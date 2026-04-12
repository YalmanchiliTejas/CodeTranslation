#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  ll a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  priority_queue<ll, vector<ll>, greater<ll>> q;
  q.push(a*x+b*y);
  q.push(c*max(x,y)*2);
  q.push(c*min(x,y)*2+a*(x-min(x,y))+b*(y-min(x,y)));
  cout << q.top() << endl;
}