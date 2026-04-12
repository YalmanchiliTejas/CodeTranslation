#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define PB push_back
#define MP make_pair
#define LL long long 
const int INF = 1145141919;
 
int main(){
  while (1){
    int n;
    int deta[100003];
    cin >> n;
    if (n == 0) return 0;
    FOR (i, 1, n + 1){
      cin >> deta[i];
      if (i % 2 == 0 && deta[i] != deta[i-1]){
	for (int j = i - 1; i > 0; j--){
	  if (deta[j] == deta[i]) break;
	  deta[j] = deta[i];
	}
      }
    }
    int ans = 0;
    FOR (i, 1, n + 1){
      if (deta[i] == 0){
	ans++;
      }
    }
    cout << ans << endl;
  }
}