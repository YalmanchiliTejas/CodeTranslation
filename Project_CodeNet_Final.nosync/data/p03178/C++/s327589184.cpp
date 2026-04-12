#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7; 
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void reads(string &s){
	char ch=getchar();s="";
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
string s;
int D,dp[10004][2][104];
int main(){
	reads(s),read(D);
	int n=s.size();s="$"+s;
	for (int i=1;i<=n;i++) s[i]-='0';
	dp[0][0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<2;j++)
			for (int k=0;k<D;k++)
				for (int l=0;l<10;l++){
					if (j==0 && l>s[i]) continue;
					if (j==0 && l==s[i]){
						dp[i][j][(k+l)%D]=(dp[i][j][(k+l)%D]+dp[i-1][j][k])%MOD;
						continue;
					}
					dp[i][1][(k+l)%D]=(dp[i][1][(k+l)%D]+dp[i-1][j][k])%MOD;
				}
	write((dp[n][0][0]+dp[n][1][0]-1+MOD)%MOD);
}