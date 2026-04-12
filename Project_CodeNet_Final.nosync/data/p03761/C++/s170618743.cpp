#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  vector<int>cnt(30,1e9);
  rep(i,n){
    string s;
    cin>>s;
    vector<int>tcnt(30);
    for(auto c:s){
      tcnt[c-'a']++;
    }
    rep(i,27){
      chmin(cnt[i],tcnt[i]);
    }
  }
  string res="";
  rep(i,27){
    rep(j,cnt[i])res+=(char)('a'+i);
  }
  cout<<res<<endl;
}
