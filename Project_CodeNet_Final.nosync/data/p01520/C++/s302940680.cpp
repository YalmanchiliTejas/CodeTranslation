#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin(); it!=(c).end(); it++)
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define pr(a) cout << (a) << endl
typedef long long ll;
typedef pair<int,int> P;
const int MAX=1000000000;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int main() {
  int n,t,e;
  cin >> n >> t >> e;
  int ans=-1;
  rep(i,n) {
    int x;
    cin >> x;
    int k=x;
    bool ck=false;
    while(k<=t+e) {
      if(k>=t-e && k<=t+e) {
	ck=true;
	break;
      }
      k+=x;
    }
    if(ck) ans=i+1;
  }
  pr(ans);
  return 0;
}
