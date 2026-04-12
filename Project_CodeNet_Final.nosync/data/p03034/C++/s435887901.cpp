#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int N; cin >> N;
    vector<int> s(N);
    rep(i,N) cin >> s[i];
    ll ans = -LINF;
    repr(i,1,N){
        ll now = 0;
        set<int> st;
        ll x = 0;
        while(x*i < N){
            int A = N-1-x*i;
            if(A <= i) break;
            if(A == x*i) break;
            if(st.find(x*i) != st.end() || st.find(A) != st.end()) break;
            st.insert(x*i);
            st.insert(A);
            now += s[x*i];
            now += s[A];
            ans = max(ans,now);
            x++;
        }
    }
    cout << ans << endl;
}
