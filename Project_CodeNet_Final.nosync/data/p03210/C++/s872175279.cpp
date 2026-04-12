#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 1e9
#define ALL(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define max(v) *max_element(v.begin(), v.end())
#define min(v) *min_element(v.begin(), v.end())
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int MOD=1000000007;

int main(void){
  int n;
  cin>>n;
  if(n==3 || n==5 || n==7)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}