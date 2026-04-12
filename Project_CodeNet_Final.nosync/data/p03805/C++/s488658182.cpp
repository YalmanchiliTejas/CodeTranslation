#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long int ll;
typedef vector<int > vecint;
typedef vector<bool > vecbool;
typedef vector<string > vecstr;
typedef vector<vector<int > > vec2int;
typedef vector<vector<bool > > vec2bool;
int dx[4] {-1,+1, 0, 0};
int dy[4] { 0, 0,-1,+1};
int main()
{
  int n, m;
  cin >> n >> m;
  vector<list<int> > a(n);
  int x, y;
  REP(i,m){
    cin >> x >> y;
    a[x - 1].push_back(y - 1);
    a[y - 1].push_back(x - 1);
  }
  //////////////////////////////
  // REP(i,n){
  //   cout << i << ", ";
  //   for(auto itr = a[i].begin(); itr != a[i].end(); itr++){
  //     cout << *itr << " ";
  //   }
  //   cout << endl;
  // }
  //////////////////////////////
  vecint arr(n - 1,0);
  REP(i,n - 1){
    arr[i] = i + 1;
  }
  //////////////////////////////
  int ans = 0;
  bool ok;
  do{
    ok = true;
    int x = 0;
    int y;
    REP(i,n-1){
      y = arr[i];
      if(count(all(a[x]),y) == 0){
	ok = false;
	break;
      }
      x = y;
    }
    if(ok){
      // REP(i,n - 1){
      // 	cout << setw(2) <<arr[i];
      // }
      // cout << endl;
      ans++;
    }
  }while(next_permutation(all(arr)));
  cout << ans << endl;

}
