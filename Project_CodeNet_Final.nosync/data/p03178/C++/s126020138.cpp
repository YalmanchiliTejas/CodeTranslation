#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
int32_t main(){
	//digit DP
	//f(index,sum,same)
	string k;
	cin>>k;
	int d; cin>>d;
	int f[k.length()+5][d+5][2];
	memset(f,0,sizeof(f));
	for(int j=0; j<=k[0]-'0'; j++){
		int v = j%d;
		if(j < k[0]-'0') f[0][v][0]++;
		else if(j==k[0]-'0')  f[0][v][1]=1;
		//cout<<0<<' '<<j<<' '<<f[0][j][0]<<' '<<f[0][j][1]<<endl;
	}
	for(int i=1; i<k.length(); i++){
		for(int j=0; j<=d; j++){
			for(int ne=0; ne<=9; ne++){ //new value
				int pv = j-ne; //prev sum
				while(pv < 0) pv+=d;
				
				if(ne == k[i]-'0') f[i][j][1] += f[i-1][pv][1];
				if(ne < k[i]-'0') f[i][j][0] += f[i-1][pv][1];
				
				f[i][j][0] += f[i-1][pv][0];
				f[i][j][0] %= MOD;
				f[i][j][1] %= MOD;
				//cout<<i<<' '<<j<<' '<<ne<<' '<<f[i][j][0]<<' '<<f[i][j][1]<<endl;
			}
			//cout<<i<<' '<<j<<' '<<f[i][j][0]<<' '<<f[i][j][1]<<endl;
		}
	}
	int t=f[k.length()-1][0][0] + f[k.length()-1][0][1];
	//cout<<f[k.length()-1][0][0] << ' '<<f[k.length()-1][0][1]<<endl;
	t%=MOD;
	t--;
	if(t<0) t+=MOD;
	cout<<t;
}