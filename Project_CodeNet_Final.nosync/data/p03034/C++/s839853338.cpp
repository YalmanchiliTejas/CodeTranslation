#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <tuple>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b))
#define mt(a,b,c) make_tuple((a),(b),(c))

typedef long long ll;

int main(){
    int n; cin >> n;
    vector<long long int> s(n); rep(i,n) cin >> s[i];
    ll ans = 0;

    for(int k=1;k<n;k++){
        set<long long int> st; 
        ll t = 0;
        ll x = 0;
        while((x+1)*k < n){
            int a = (n-1)-x*k;
           // int b = a - k; if(b <= 0) break;
            if(st.count(x*k) > 0 || st.count(n-1-x*k) > 0 || x*k == n-1-x*k) break;
            st.insert(x*k); st.insert(n-1-x*k); 
            t += s[n-1-x*k] + s[x*k];
            ans = max(ans, t);
            x++;
        }
    }
    cout << ans << endl;
    return 0;
}