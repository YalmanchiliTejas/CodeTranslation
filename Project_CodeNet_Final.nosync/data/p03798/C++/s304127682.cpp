#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

ll N;
string S;

char SW(char a1, char a2, char xo){
  if(((a1 == a2) && (xo == 'o')) || ((a1 != a2) && (xo == 'x'))){
    return 'S';
  } else{
    return 'W';
  }    
}

int main(){
  cin >> N;
  cin >> S;

  vc r(N);

  vector<pair<char, char>> init(4);

  init[0] = {'S', 'S'};
  init[1] = {'S', 'W'};
  init[2] = {'W', 'S'};
  init[3] = {'W', 'W'};
  
  rep(i, 4){
    r[0] = init[i].first;
    r[1] = init[i].second;

    rep2(j, 2, N) r[j] = SW(r[j - 2], r[j - 1], S[j - 1]);

    if((SW(r[N - 2], r[N - 1], S[N - 1]) == r[0]) && (SW(r[N - 1], r[0], S[0]) == r[1])){
      rep(j, N) cout << r[j];
      cout << endl;

      return 0;
    }
  }

  cout << -1 << endl;
  
  return 0;
}
