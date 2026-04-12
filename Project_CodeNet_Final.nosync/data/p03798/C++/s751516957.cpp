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
  vector<int>ss(n);
  cin>>s;
  rep(i,n)ss[i]=s[i]=='x';
  rep(i,4){
    bitset<2>ti=i;
    vector<int>ft(n+1);
    ft[0]=ti[0];
    ft[1]=ti[1];
    rep(j,n-1){
      ft[j+2]=ft[j+1]^ss[j+1]^ft[j];
    }
    if(ft[n]==ft[0]&&ft[n-1]==(ft[0]^ss[0]^ft[1])){
      rep(j,n){
        if(!ft[j])cout<<"S";
        else cout<<"W";
      }
      cout<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;

  return 0;

}
