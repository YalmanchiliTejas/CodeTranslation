#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl


int main(){
    string s;
    ll K;
    cin >> s;
    cin >> K;

    ll dp[101][2][5]={0,};

    int len = s.size();

	dp[0][0][0] = 1;

	for ( int i = 0; i < len; ++i ){
		const int D = s[i] - '0';
		for ( int j = 0; j < 2; ++j ){
			for ( int k = 0; k < 4; ++k ){
				for ( int d = 0; d <= ( j ? 9 : D ); ++d ){
                    if(d==0){
                        dp[ i + 1 ][ j || ( d < D ) ][ k ] += dp[i][j][k];
                    }else{
                        int v = k+1;
                        if(k+1==5){v--;}
                        dp[ i + 1 ][ j || ( d < D ) ][ v ] += dp[i][j][k];
                    }
				}
			}
		}
	}
    cout << dp[len][0][K]+dp[len][1][K] << endl;
    return 0;

}
