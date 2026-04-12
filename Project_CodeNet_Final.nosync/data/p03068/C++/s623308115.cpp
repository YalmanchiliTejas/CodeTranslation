#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <set>
#define INF 1000000000
#define LLINF 2000000000000000
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LOOP(i,N) for(int i=0;i<N;i++)
#define LOOP1(i,N) for(int i=1;i<=N;i++)
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
// #define int long long

signed main(){
  int n;
  string s;
  int k;
  cin >> n >> s >> k;
  char c = s[k-1];
  LOOP(i,n){
    if(s[i] != c){
      s[i] = '*';
    }
  }
  cout << s << endl;
}
