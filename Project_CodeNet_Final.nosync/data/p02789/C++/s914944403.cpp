#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> VI;
typedef vector<VI> VVI;//例: VVI dp(10, vector<int>(10, INF);
typedef priority_queue<int, vector<int>, less<int> > QUE_int;
const int INF = pow(10, 5)+1;//+1しないとREになる(out of rangeになるんかな?? )


int main(){
  int N, M;
  cin >> N >> M;
  if(N==M) cout << "Yes" << endl;
  else cout << "No" << endl;
}
