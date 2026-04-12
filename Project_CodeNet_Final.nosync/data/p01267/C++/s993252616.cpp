#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<P,P> PP;
const ll MOD = 1000000007;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(1e5 + 5);
const double EPS = 1e-10;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define ALL(v) (v).begin(), (v).end()

int main() {
    int n, a, b, c, x;
    while(cin >> n >> a >> b >> c >> x, n){
        int y[105];
        REP(i,n) cin >> y[i];
        int cnt = 0, k=0;
        while(k<n && cnt<=10000){
            if(x==y[k])k++;
            x = (a*x+b)%c;
            cnt++;
        }
        cnt--;
        if(k==n && cnt<=10000){
            cout << cnt << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}

