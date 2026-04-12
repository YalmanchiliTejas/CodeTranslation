/*
读题不规范，爆零两行泪。
数据不清空，爆零两行泪。
多测不读完，爆零两行泪。
边界不特判，爆零两行泪。
贪心不证明，爆零两行泪。
D P 顺序错，爆零两行泪。
大小少等号，爆零两行泪。
变量不统一，爆零两行泪。
越界不判断，爆零两行泪。
调试不注释，爆零两行泪。
溢出不 l l，爆零两行泪。
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int N=2000;
int n;
int a[3*N+1];
int dp[N+1][N+1];
int mx_r[N+1],mx_c[N+1];
bool added;
int real_dp(int x,int y){return max(dp[x][y],max(mx_r[x],mx_c[y]))-added;}
vector<pair<int*,int> > chg;
void chkmx(int &x,int y){chg.pb(mp(&x,y));}
int main(){
	cin>>n;
	for(int i=1;i<=3*n;i++)scanf("%d",a+i);
	reverse(a+1,a+3*n+1);
//	for(int i=1;i<=3*n;i++)cout<<a[i]<<" ";puts("");
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=a[1]==i&&i==j;
	int add=0;
	for(int i=2;i<=n;i++){
		if(a[3*i-4]==a[3*i-3]&&a[3*i-3]==a[3*i-2])add++,added=true;
		else added=false;
		chg.clear();
		for(int j=3*i-4;j<=3*i-2;j++){
			vector<int> v;
			for(int k=3*i-4;k<=3*i-2;k++)if(k!=j)v.pb(a[k]);
			for(int k=1;k<=n;k++)chkmx(mx_r[k],real_dp(v[0],v[1]));
			chkmx(dp[a[j]][a[j]],real_dp(v[0],v[1])+1);
		}
		for(int j=1;j<=n;j++){
			for(int k=3*i-4;k<=3*i-2;k++){
				chkmx(mx_r[j],real_dp(j,a[k])),chkmx(mx_c[j],real_dp(j,a[k]));
				vector<int> v;
				for(int o=3*i-4;o<=3*i-2;o++)if(o!=k)v.pb(a[o]);
				if(v[0]==v[1])chkmx(dp[j][v[0]],real_dp(j,a[k])+1),chkmx(dp[v[0]][j],real_dp(j,a[k])+1);
			}
		}
		for(int j=0;j<chg.size();j++)*chg[j].X=max(*chg[j].X,chg[j].Y);
	}
	added=false;
	cout<<real_dp(a[3*n],a[3*n-1])+add;
	return 0;
}