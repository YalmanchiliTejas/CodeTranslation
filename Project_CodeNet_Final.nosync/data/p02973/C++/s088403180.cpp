#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int n;
  cin >> n;
  int a[n]={};
  multiset<int> se;
  rep(i,n){
    cin >> a[i];
  }
  int ans=0;
  rep(i,n){
    if(i==0){
      se.insert(a[i]);
      continue;
    }
    auto it=se.lower_bound(a[i]);
    if(it==se.begin()){
      se.insert(a[i]);
    }else{
      it--;
      se.erase(it);
      se.insert(a[i]);
    }
  }
//  for(auto i=se.begin();i!=se.end();i++)cout << *i << endl;
  cout << se.size() << endl;
return 0;}