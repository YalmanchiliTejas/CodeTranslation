#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <set>
#define INF 1000000000
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LOOP(i,N) for(int i=0;i<N;i++)
#define LOOP1(i,N) for(int i=1;i<=N;i++)
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;

#define int long long

signed main(){
  int h[20];
  int N;
  int nh = 0;
  cin >> N;
  int ans = 0;
  LOOP(i,N){
    cin >> h[i];
  }
  LOOP(i,N){
    if(h[i]>=nh){
      nh = h[i];
      ans++;
    }
  }
  cout << ans << endl;
}
