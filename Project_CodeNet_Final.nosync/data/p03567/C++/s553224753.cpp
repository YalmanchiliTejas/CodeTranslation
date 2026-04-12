#include <bits/stdc++.h>
using namespace std;

#define PI 4*atan(1)
#define INF 1e8

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)

typedef long long ll;
typedef pair<int, int> P;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
  string S;
  cin >> S;
  for(int i = 0; i < S.size() - 1; i++){
    if(S[i] == 'A' &&  S[i + 1] == 'C'){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
