//by szh
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define SZ(x) (int((x).size()))
#define se second
#define ll long long
#define pq priority_queue
#define MP make_pair
#define pii pair<int,int>
#define mod 998244353
#define debug(x) cerr<<#x<<"="<<x<<'\n'

char s[200];
int k;
ll f[200][2][10];
//0:< 1:=

int main(){
	cin>>s+1>>k;
	memset(f,0ll,sizeof(f));
	f[1][0][0]=1;
	f[1][0][1]=(ll)(s[1]-'1');
	f[1][1][1]=1;
	for (int i=1;i<strlen(s+1);i++) 
		for (int j=0;j<=k;j++) {
			//non-zero
			f[i+1][0][j+1]+=f[i][0][j]*9ll+f[i][1][j]*max(0ll,(ll)(s[i+1]-'1'));
			if (s[i+1]!='0') f[i+1][1][j+1]+=f[i][1][j];
			//zero
			f[i+1][0][j]+=f[i][0][j];
			if (s[i+1]!='0') f[i+1][0][j]+=f[i][1][j];
			else f[i+1][1][j]+=f[i][1][j];
//			printf("%d %d ",f[i+1][0][j+1],f[i+1][1][j+1]);
//			printf("f[%d][0][%d]=%d f[%d][1][%d]=%d\n",i,j,f[i][0][j],i,j,f[i][1][j]);
		}
	cout<<f[strlen(s+1)][0][k]+f[strlen(s+1)][1][k];
	return 0;
}