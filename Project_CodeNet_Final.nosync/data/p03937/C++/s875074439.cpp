#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
 
#define rep(i,n) for(int i = 0;i < (n);i++)
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pair<int, int> > vpi;
typedef vector<pair<ll, ll> > vpl;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w;
  cin >> h >> w;
  char a[8][8];
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
    }
  }
 
  int di = 0;
  rep(i,h){
    int count = 0;
    rep(j,di){
      if(a[i][j] == '#'){
        cout << "Impossible" << endl;
        return 0;
      }
    }
    if(i == h-1) break;
    for(int j=di;j < w;j++){
      if(count != 0 && a[i][j] == '#'){
        cout << "Impossible" << endl;
        return 0;
      }
      if(a[i][j] == '#' && a[i+1][j] == '#'){
        di = j;
        count++;
      }
    }
    if(count != 1){
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
	return 0;
}
