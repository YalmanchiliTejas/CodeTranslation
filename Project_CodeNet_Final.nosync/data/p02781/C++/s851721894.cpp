#include<bits/stdc++.h>
using namespace std ;
#define pb push_back
#define ll long long
vector<ll>vec ;
ll len ;
ll dp[200][5][2] ;
ll k ;
void gen(string s ) {
    vec.clear() ;

    for(ll i=0;i<s.size();i++) vec.pb( (int) s[i]-'0') ;
    len = vec.size() ;
}

ll digit_dp(ll pos , ll not_zero , ll is_big ) {
    if (not_zero>k) return 0LL ;
    if (pos>=len) return 1LL ;
    if (dp[pos][not_zero][is_big]!=-1) return dp[pos][not_zero][is_big] ;
    ll lim , ans = 0 , i , nxt_big , nxt_zero ;
    if (is_big) lim = vec[pos] ;
    else lim = 9 ;

    for(i=0;i<=lim;i++) {
        if (is_big and (lim==i) ) nxt_big = 1 ;
        else nxt_big = 0 ;

        if (i) nxt_zero = not_zero+1 ;
        else nxt_zero = not_zero ;

        ans+= digit_dp(pos+1 , nxt_zero,nxt_big ) ;


    }

    return dp[pos][not_zero][is_big] = ans ;

}




int main() {
    string s ;
    cin >> s >>  k ;
    gen(s) ;

    memset(dp,-1,sizeof(dp)) ;
    ll left =  digit_dp(0,0,1) ;
    k-- ;
    memset(dp,-1,sizeof(dp)) ;
    ll right = digit_dp(0,0,1) ;
    cout << left -right ;


    return 0 ;
}
