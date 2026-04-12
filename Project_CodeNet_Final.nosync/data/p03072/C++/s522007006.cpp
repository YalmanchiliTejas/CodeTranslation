#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define FORR(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)

#define CHMIN(a, b) (a) = min((a), (b))
#define CHMAX(a, b) (a) = max((a), (b))

#define DEBUG(x) cout << #x << ": " << (x) << endl
#define PRINT(x) cout << x << endl
#define all(x) x.begin(),x.end()


int main() {
    int N;
    cin >> N;
    vi H(N,0);
    vi m(N,0);
    
    REP(i,N){
        cin >> H[i];
    }

    m[0]=H[0];
    FOR(i,1,N){
        m[i] = max(m[i-1],H[i]);
    }

    int rep=0;
    REP(i,N){
        if(m[i]<=H[i]) rep++;
    }

    PRINT(rep);


}


