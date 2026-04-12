#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define rep(n, i) Rep(0, n-1, i)
#define INF 10000000

typedef long long ll;
typedef pair<ll, ll> P;
typedef std::priority_queue<int> IntPrioQueue; //Z->A
typedef std::priority_queue<int, std::vector<int>, std::greater<int> > IntReversePrioQueue; //A->Z


int dx4[4]={1,0,-1,0};
int dy4[4]={0,1,0,-1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};

void solve(void){
    int n;
    cin >> n;
    int atoz[26]; fill(atoz, atoz+26, INF);
    int apperances[n][26];
    string temps;
    rep(n, i){
        cin >> temps;
        rep(26, j) apperances[i][j] = count(temps.begin(), temps.end(), (char)(j + 'a'));
    }
    rep(26, i) {
        int m = INF;
        rep(n, j) m = min(apperances[j][i], m);
        rep(m, k) cout << (char)(i + 'a');
    }
    cout << '\n';
}

int main(void){
  solve();
  return 0;
}
