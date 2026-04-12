#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const double PI = acos(-1);
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;

#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i = 0; i<n; i++)
#define ALL(a) begin(a), end(a)

int main (void) {
    int N,K;
    string S;
    cin>>N>>S>>K;
    string ans;
    char t = S[K-1];
    REP(i,N) {
        if (S[i] != t) {
            ans.pb('*');
        }
        else {
            ans.pb(S[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}