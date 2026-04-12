#include<bits/stdc++.h>
using namespace std;
int dp1[100005][105],dp2[100005][105];
string k;
int d;
int main() {
	cin >> k;
	cin >> d;
	dp1[0][0] = 1;
	k = " " + k;
	for(int i=1; i<k.length(); i++) {
		for(int j=0; j<d; j++) {
			for(int l=0; l<k[i]-'0'; l++) {
				dp2[i][(l+j)%d] += dp1[i-1][j];
				dp2[i][(l+j)%d] %= 1000000007;
			}
			for(int l=0; l<10; l++) {
				dp2[i][(l+j)%d] += dp2[i-1][j];
				dp2[i][(l+j)%d] %= 1000000007;
			}
			dp1[i][(k[i]-'0'+j)%d] += dp1[i-1][j];
			dp1[i][(k[i]-'0'+j)%d] %= 1000000007;
		}
	}
	cout << (dp1[k.length()-1][0] + dp2[k.length()-1][0]-1+1000000007)%1000000007 << endl;
}