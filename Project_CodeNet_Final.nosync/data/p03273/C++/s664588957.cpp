#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
#include <exception>
#include <numeric>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<ll, ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<P> vp;
typedef vector<bool> vb;
#define rep(i, a, n) for (ll i = (a); i < (n); ++i)
#define rrep(i, a, n) for (ll i = (a); i > (n); --i)
#define erep(i, a, n) for (ll i = (a); i <= (n); ++i)
#define rerep(i, a, n) for (ll i = (a); i >= (n); --i)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)x.size())
#define print(X) cout << (X) << "\n"
#define _ << " " <<
static const int INF = 1e+9+7;


// 回答写経です
int main(){
    int h;
    cin >> h;
    int w;
    cin >> w;
    vs a(h);
    rep(i,0,h) cin >> a[i];
    
// 縦と横の正誤をチェックするための配列を作る
    vb row(h, false);
    vb col(w, false);
    rep(i,0,h){
      rep(j,0,w){
        // その行に1つでも#があればその行は出力しても良い
        if(a[i][j] == '#') {
          row[i] = true;
          col[j] = true;
        }
      }
    }

    // 出力
    rep(i,0,h){
      if(row[i]){
        rep(j,0,w){
          if(col[j]){
            cout << a[i][j];
          }
        }
        cout << endl;
      }
    }

    return 0;
    
  }

