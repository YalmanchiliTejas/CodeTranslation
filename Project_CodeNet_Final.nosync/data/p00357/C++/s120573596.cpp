#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR1(i,n) for(int (i)=1;(i)<(n);(i)++)
#define eFOR(i,n) for(int (i)=0;(i)<=(n);(i)++)
#define eFOR1(i,n) for(int (i)=1;(i)<=(n);(i)++)
#define SORT(i) sort((i).begin(),(i).end())
#define rSORT(i) sort((i).begin(),(i).end(), greater<int>());
#define YES(i) cout << ((i) ? "Yes" : "No") << endl;
#define INF = 1000000000;
#define LLINF = 1LL << 62;
#define mod = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; }return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; }return 0; }

int main() {
    int n;
    cin >> n;
    VI d(n);
    FOR(i, n){
        cin >> d[i];
        d[i] /= 10;
    }

    int f = 0;
    eFOR(i, min(n - 1, f))chmax(f, i + d[i]);
    int b = n - 1;
    for (int i = n - 1; i >= max(0, b); i--)chmin(b, i - d[i]);
    cout << (f >= n - 1 && b <= 0 ? "yes" : "no") << endl;
}

