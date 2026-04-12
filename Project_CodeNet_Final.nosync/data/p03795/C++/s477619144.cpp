#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long lng;
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define FORD(i,b,a) for(int i=(b); i>=(a); --i)
#define REP(i,n) FOR(i,0,n-1)
#define ALL(a) (a).begin(), (a).end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end()) //NOTE: <a> must be sorted in advance

lng power(lng b, lng n) {lng sol=1; while(n>0) {if(n&1) {sol=sol*b;} n>>=1; b*= b;} return sol;} //calculate b^n

const int MOD = 1000000007; //10^9+7


/*********** variables ************/
int N;
/**********************************/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    int ans = N*800;
    ans -= 200*(N/15);
  cout << ans << endl;
}
