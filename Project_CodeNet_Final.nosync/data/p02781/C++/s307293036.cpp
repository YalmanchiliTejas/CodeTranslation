#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
ll ch[102][5][2];
int main() {
	string s;
	cin>>s;
	ll m;
	cin>>m;
	ch[0][0][0]=1;
	for(ll i=0;i<s.size();i++){
		ll now=s[i]-'0';
		for(ll j=0;j<10;j++){
			for(ll k=0;k<=3;k++){
				if(j==0){
					if(j==now){
						ch[i+1][k][0]+=ch[i][k][0];
					}
					else if(j<now){
						ch[i+1][k][1]+=ch[i][k][0];
					}
					ch[i+1][k][1]+=ch[i][k][1];
				}
				else{
					if(j==now){
						ch[i+1][k+1][0]+=ch[i][k][0];
					}
					else if(j<now){
						ch[i+1][k+1][1]+=ch[i][k][0];
					}
					ch[i+1][k+1][1]+=ch[i][k][1];					
				}
			}
		}
	}
	cout << ch[s.size()][m][0]+ch[s.size()][m][1];
	// your code goes here
	return 0;
}