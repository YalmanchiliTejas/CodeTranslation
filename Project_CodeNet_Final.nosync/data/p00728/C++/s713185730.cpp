#include "bits/stdc++.h"
using namespace std;
#define CK(N, A, B) (A <= N && N < B)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = (b - 1); a <= i; i--)
#define F first
#define S second
typedef long long ll;

const int INF = 1e9 + 7;
const long long LLINF = 1e18;

ll n;
int main() {
    while(cin>>n, n!=0){
        ll s;
        ll mx=-LLINF, mn=LLINF, sum=0;
        REP(i, 0, n){
            cin>>s;
            mx=max(mx, s);
            mn=min(mn, s);
            sum+=s;
        }

        cout<<(sum-mx-mn)/(n-2)<<endl;
    }
    return 0;
}
