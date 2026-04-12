#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
	ll ch[102][5][2];
int main() {
	ll k;
	string s;
	cin>>s>>k;
	ch[0][0][0]=1;
	for(ll i=0;i<s.size();i++){
		for(ll j=0;j<=9;j++){
			ll now=s[i]-'0';
			if(now<j){
				if(j==0){
					for(ll l=0;l<4;l++){
						ch[i+1][l][1]+=ch[i][l][1];
					}
				}
				else{
					for(ll l=0;l<4;l++){
						ch[i+1][l+1][1]+=ch[i][l][1];
					}					
				}
			}
			else if(now==j){
				if(j==0){
					for(ll l=0;l<4;l++){
						ch[i+1][l][0]+=ch[i][l][0];
						ch[i+1][l][1]+=ch[i][l][1];
					}
				}
				else{
					for(ll l=0;l<4;l++){
						ch[i+1][l+1][0]+=ch[i][l][0];
						ch[i+1][l+1][1]+=ch[i][l][1];
					}					
				}				
			}
			else if(now>j){
				if(j==0){
					for(ll l=0;l<4;l++){
						ch[i+1][l][1]+=ch[i][l][0];
						ch[i+1][l][1]+=ch[i][l][1];
					}
				}
				else{
					for(ll l=0;l<4;l++){
						ch[i+1][l+1][1]+=ch[i][l][0];
						ch[i+1][l+1][1]+=ch[i][l][1];
					}					
				}					
			}
		}
	}
	cout << ch[s.size()][k][0]+ch[s.size()][k][1];
	// your code goes here
	return 0;
}