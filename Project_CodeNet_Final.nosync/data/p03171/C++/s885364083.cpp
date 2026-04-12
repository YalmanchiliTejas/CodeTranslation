#include <bits/stdc++.h>
#define int long long 
#define double long double 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
        enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
        ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
                *this << ", " + 2 * (it == d.b) << *it;
        ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int32_t main(){
        IOS;
        int n ;
        cin >> n ;
        vector<int>arr(n);
        for(int& i : arr) cin >> i ;
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n-1;i>=0;i--){
                for(int j=i;j<n;j++){
                        if(i==j){
                                dp[i][j] = arr[i];
                        }else{
                                dp[i][j] = max(arr[i] - dp[i+1][j],arr[j] - (j>0?dp[i][j-1]:0));
                        }
                } 
        }
        cout << dp[0][n-1] << endl;
        return 0;
}