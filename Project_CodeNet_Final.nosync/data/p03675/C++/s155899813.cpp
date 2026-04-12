#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
#define REP(i, limit) for(int i=0; i< limit; ++i)
#define FOR(i, j, limit) for(int i=j; i< limit; ++i)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define LL long long
int INF = 2147483647;
LL LINF = 9223372036854775807;
LL MOD = 1000000007;
typedef pair<int, int>P;
typedef pair<LL, LL>PL;
typedef vector<int> vi;
typedef vector<LL> vl;


int main(){
  int n;
  cin>>n;
  int a[n];
  REP(i, n)cin>>a[i];
  if(n==1){
    cout<<a[0]<<endl;
    return 0;
  }

  int b[n];
  if(n%2){
    REP(i, n/2+1) b[i] = a[n-1-i*2];
    for(int i=n/2+1; i<n; ++i) b[i] = a[2*(i-n/2)-1];
  }
  else{
    REP(i, n/2) b[i] = a[n-1-i*2];
    for(int i=n/2; i<n; ++i) b[i] = a[2*(i-n/2)];
  }

  REP(i, n-1)cout<<b[i]<<" ";
  cout<<b[n-1]<<endl;


  return 0;
}
