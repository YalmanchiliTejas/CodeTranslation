#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=10010,D=110,mod=1e9+7;
int n,d;
string k;
ll dp[N][D][2];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>k>>d;
	n=k.size();
	dp[0][0][1]=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<d;++j){
			for(int l=0;l<10;++l)
				dp[i+1][(j+l)%d][0]=(dp[i+1][(j+l)%d][0]+dp[i][j][0]+(l+'0'<k[i])*dp[i][j][1])%mod;
			dp[i+1][(j+k[i]-'0')%d][1]=dp[i][j][1];
		}
	cout<<(dp[n][0][0]+dp[n][0][1]-1+mod)%mod<<endl;		
}
