#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define F first
#define S second
#define db(x) cerr << #x << ": " << x << "\n";

int N;
vector<ll> A;
bool calc[100010][5][5];
ll dp[100010][5][5];

/*
    state:
    0 -> only jumps from i to i+2
    1 -> one jump from i to i+3
    2 -> two jumps from i to i+3
    3 -> one jump from i to i+4
*/

ll f(int done, int state, int offset) {
    if(done == N/2)
        return 0LL;

    int ind = 0;
    if(state == 0) 
        ind = offset + done * 2;
    else if(state == 1) 
        ind = offset + (done-1) * 2 + 3;
    else if(state == 2)
        ind = offset + (done-2) * 2 + 6;
    else if(state == 3) 
        ind = offset + (done-1) * 2 + 4;
    
    if(ind >= N)
        return LLONG_MIN;
    
    if(calc[done][state][offset])
        return dp[done][state][offset];
    calc[done][state][offset] = true;

    ll res = 0;
    if(state == 0) 
        res = max({f(done+1, 0, offset), f(done+1, 1, offset), f(done+1, 3, offset)});
    else if(state == 1)
        res = max(f(done+1,1,offset), f(done+1,2,offset));
    else if(state == 2 || state == 3)
        res = f(done+1,state,offset);
    
    return dp[done][state][offset] = (res == LLONG_MIN ? LLONG_MIN : A[ind] + res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    A.resize(N);
    for(ll & x : A) cin >> x;
    
    memset(calc, false, sizeof calc);

    ll res = LLONG_MIN;
    if(N%2)
        res = max({f(0,0,0),f(0,0,1),f(0,0,2)});
    else 
        res = max(f(0,0,0),f(0,0,1));
    
    cout << res << '\n';
}
