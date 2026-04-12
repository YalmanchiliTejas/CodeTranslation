#include "bits/stdc++.h"

#define REP(i, n, N) for(ll i=(n); i<(N); i++)
#define RREP(i, n, N) for(ll i=(N-1); i>=(n); i--)
#define LREP(lst,itr) for(auto itr = lst.begin(); itr != lst.end(); ++itr)
#define CK(n, a, b) ((a)<=(n)&&(n)<(b))
#define ALL(v) (v).begin(),(v).end()
#define MCP(a, b) memcpy(b,a,sizeof(b))
#define P(s) cout<<(s)<<endl
#define P2(a, b) cout<<(a)<<" "<<(b)<<endl
#define P3(a, b, c) cout<<(a)<<" "<<(b)<<" "<<(c)<<endl
#define V2(T) vector<vector<T>>
typedef long long ll;
using namespace std;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main(){
    int N, gift;
    cin >> N;
    gift = N/15;
    P(N*800 - gift*200);
}