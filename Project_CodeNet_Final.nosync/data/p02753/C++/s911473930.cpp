#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define PB push_back
#define SP << " " <<

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;

__attribute__((constructor))
void initial(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed <<setprecision(15);
}


int main(void){
	string S;
    cin >> S;
    string ans = "No";
    rep(i,2){
        if(S[i] != S[i+1]) ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}
