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
  int n;cin>>n;
  string s;
  cin>>s;
  rep(i,4){
    bitset<2>ti=i;
    vector<int>tf(n+1);
    tf[0]=ti[0];
    tf[1]=ti[1];
    rep(j,n-1){
      tf[j+2]=(tf[j+1]!=1)^(s[j+1]!='o')^tf[j];
    }
    if(tf[n]==tf[0]&&tf[n-1]==((tf[0]!=1)^(s[0]!='o')^tf[1])){
      rep(j,n){
        if(tf[j])cout<<"S";
        else cout<<"W";
      }
      cout<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;

  return 0;

}
