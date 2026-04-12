#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, n) for(int i = (a); i < (n); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << '\n'

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  vector<int> a;

  while(true){
    vector<int> a;
    cin >> N;

    if(N == 0) break;

    int b;
    REP(i, N) {
      cin >> b;
      a.push_back(b);
    }

    sort(a.begin(), a.end());

    int sum = 0;
    FOR(i, 1, N - 1) {
      sum += a[i];
    }
    sum = sum / (N - 2);
    
    cout << sum << endl;

  }




}

