#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define vint vector<int >
#define vll vector<ll >
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i,n) for (int i = 0; i < (n); ++i)
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x;
    cin >> x;
    if(x >= 30){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    return 0;
}