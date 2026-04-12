#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>
#define ll long long
#define MAX 25 * 1e13
#define N  200010

#define SIZE(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define EB(X) emplace_back(X)
#define REP(i,a) for(int i=0;i<(a);++i)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define range(a) a.begin(), a.end()
#define VI vector<int>;

using namespace std;
int MOD = 1000000007;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string a;
  cin >> a;
  int lena = a.size();
  int cnta = 0;
  REP(i,lena) {
    if( a[i] == 'A' ) cnta++;
  }
  if( cnta == 3 || cnta == 0 ) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}

