#include <iostream>
#include <string>
#define ll long long
using namespace std;

ll mod=1000000007, dp[10010][110][2];

int main() {
	string K;
	int D;
	cin >> K >> D;
	dp[0][0][0]=1;
	for(int i=0; i<K.size(); ++i){
	    for(int j=0; j<D; ++j){
	        for(int r=0; r<10; ++r){
	            dp[i+1][(j+r)%D][1]=(dp[i+1][(j+r)%D][1]+dp[i][j][1])%mod;
	            if(r<K[i]-'0') dp[i+1][(j+r)%D][1]=(dp[i+1][(j+r)%D][1]+dp[i][j][0])%mod;
	            if(r==K[i]-'0') dp[i+1][(j+r)%D][0]=(dp[i+1][(j+r)%D][0]+dp[i][j][0])%mod;
	        }
	    }
	}
	cout << (dp[K.size()][0][0]+dp[K.size()][0][1]+mod-1)%mod << endl;
	return 0;
}
