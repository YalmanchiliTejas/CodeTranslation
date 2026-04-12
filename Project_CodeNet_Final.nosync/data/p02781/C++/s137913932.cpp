#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

LL C[maxn][5];

LL dfs(string s,int k){
	if(k==0||s.length()==0)return 0;
	int n=s.length(),t=s[0]-'0';
	if(t==0)return dfs(s.substr(1),k);
	else return C[n-1][k]*pow(9,k)+(t-1)*C[n-1][k-1]*pow(9,k-1)+dfs(s.substr(1),k-1);
}

int main(){
	string s;
	int k;
	cin>>s>>k;
	int n=s.length();
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i&&j<=3;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]!='0')cnt++;
	}
	if(cnt>=k)printf("%lld\n",dfs(s,k)+1);
	else printf("%lld\n",dfs(s,k));
	return 0;
}