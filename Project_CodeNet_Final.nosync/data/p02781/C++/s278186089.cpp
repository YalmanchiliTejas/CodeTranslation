#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1e9+7LL;

long long dp0[101][4]; //N未満
long long dp1[101][4];

int main() {
    string N; cin >> N;
    int K; cin >> K;

    int L = N.size();
	fill( ( long long * )dp0, ( long long * )dp0 + sizeof( dp0 ) / sizeof( long long ), 0 );
  fill( ( long long * )dp1, ( long long * )dp1 + sizeof( dp1 ) / sizeof( long long ), 0 );
	dp0[0][0] = 1;
    dp1[0][1] = 1;
    dp0[0][1] = N.at(0)-'1';

	for ( int i = 0; i < L-1; ++i ){
		for ( int j = 0; j < K+1; ++j ){
			dp0[i+1][j] = dp0[i][j];
            if(j>0) dp0[i+1][j] += 9*dp0[i][j-1];

            if(N[i+1]=='0'){
                dp1[i+1][j] = dp1[i][j];
            }
            else{
                if(j>0){
                    dp0[i+1][j] += (N[i+1]-'1')*dp1[i][j-1];
                    dp1[i+1][j] += dp1[i][j-1];
                }
                dp0[i+1][j] += dp1[i][j];
            }
		}
	}

    cout << dp0[L-1][K] + dp1[L-1][K] << endl;
}