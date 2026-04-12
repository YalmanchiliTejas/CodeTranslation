#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    ll N;
    cin >> N;
    vec _A(N);
    REP(i,0,N) cin >> _A[i];
    
    ASC(_A);
    deque<ll> A;
    FORR(a,_A) A.push_back(a);

    deque<ll> D;
    D.push_back(A.front());
    A.pop_front();
    D.push_back(A.back());
    A.pop_back();

    while(!A.empty()) {
        ll amin = A.front(), amax = A.back();
        ll dl = D.front(), dr = D.back();
        vector<pll> p = {{abs(amin-dl), 0}, {abs(amin-dr), 1}, {abs(amax-dl), 2}, {abs(amax-dr), 3}};
        DESC(p);
        if(p[0].second == 0) {
            D.push_front(amin);
            A.pop_front();
        }
        else if(p[0].second == 1) {
            D.push_back(amin);
            A.pop_front();
        } 
        else if(p[0].second == 2) {
            D.push_front(amax);
            A.pop_back();
        }
        else {
            D.push_back(amax);
            A.pop_back();
        }
    }

    ll sum = 0;
    REP(i,0,SZ(D)-1) sum += abs(D[i+1] - D[i]);
    PR(sum);

    return 0;
}

/*



*/