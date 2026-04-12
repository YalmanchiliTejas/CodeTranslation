#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  int N;
  cin>>N;
  int A[N];
  REP(i,N)cin>>A[i];
  multiset<int> s;
  s.insert(A[N-1]);
  int ans=1;
  for(int i=N-2;i>=0;i--){
    auto itr=s.lower_bound(A[i]+1);
    if(itr==s.end()){
      ans++;
    }else{
      s.erase(itr);
    }
    s.insert(A[i]);
  }
  cout<<ans<<endl;
  return 0;
}
