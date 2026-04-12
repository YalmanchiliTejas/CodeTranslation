/*------U Have To DO It------*/
/* BY-> RicoProg */
/*        ___ 
           __|__|
          |  |___       */
#include <bits/stdc++.h>
using namespace std;
 
 
//---------------------------------------------------MACROS----------------------------------------------------------
#define ll long long
#define ld long double
#define beg(i ,n) for(ll i=0;i<n;i++)
#define beg1(i ,n) for(ll i=1;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back 
#define mp make_pair
#define nl "\n" 
#define vec(v , n) vector<ll> v(n)
#define all(x) x.begin() , x.end()
#define pii pair<int , int>
#define pll pair<ll , ll>
#define mii map<int , int>
#define mll map<ll , ll>
#define msi map<string , int>
#define mci map<char , int>
#define f1 first
#define f2 second

//---------------------------------------------------GLOBAL----------------------------------------------------------
const ll MOD = 1e9 + 7 ;
const ll MAX = 1e5 + 7 ;
const ll inf = 1e18 + 5 ;

//---------------------------------------------------FUNCTIONS-------------------------------------------------------

const ll nax = 2e3 + 5 ;
ll n , k ;

void add_self(ll &a , ll b){
	a+=b ;
	if(a>MOD) a-=MOD ;
}

ll mul(ll a , ll b){
	return a * b % MOD ;
}

ll dp[10005][105][2] ;

void solve(){
	string s ;
	int d ;
	cin >> s >> d ;
	for(int i=0 ; i<=s[0]-'0' ; ++i){
		if(i!=s[0]-'0') dp[1][i%d][0] += 1 ;
		else dp[1][i%d][1] += 1 ;
	}
	ll len = s.length() ;
	for(int index=1 ; index<len ; ++index){
		for(int c_mod=0 ; c_mod<d ; ++c_mod){
			for(int digit=0 ; digit<=9 ; ++digit){
				//cout << index << " " << c_mod << " " << digit << " " << (c_mod+digit)%d << nl ;
				add_self(dp[index+1][(c_mod+digit)%d][0] , dp[index][c_mod][0]) ;
			}
			for(int digit=0 ; digit<=s[index]-'0' ; ++digit){
				if(digit<s[index]-'0'){
					//cout << index << " " << c_mod << " " << digit << nl ;
					add_self(dp[index+1][(c_mod+digit)%d][0] , dp[index][c_mod][1]) ;
				}
				else{					
					//cout << index << " " << c_mod << " " << digit << nl ;
					add_self(dp[index+1][(c_mod+digit)%d][1] , dp[index][c_mod][1]) ;
				}
			}
		}
	}
	ll answer = (dp[len][0][0] + dp[len][0][1]) % MOD ;
	--answer ;
	if(answer<0) answer+=MOD ;
	printf("%lld" , answer) ;
}

//---------------------------------------------------DRIVER----------------------------------------------------------
int main()
{
    fast ;
    int t=1 ;
    //scanf("%lld" , &t) ;
    while(t--){
        solve() ;
        //cout << "A" << nl ;
    }
    return 0;
}   