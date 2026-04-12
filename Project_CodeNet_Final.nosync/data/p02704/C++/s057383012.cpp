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
typedef unsigned long long ull;
const int N=500;
int n;
bool a[N+1],b[N+1];
ull c[N+1],d[N+1];
ull ans[N+1][N+1];
void sol(int x){
//	cout<<x<<"\n";
	vector<int> r0,ro0,r1,ro1,c0,co0,c1,co1;
	for(int i=1;i<=n;i++){
		if(!a[i]&&!(c[i]&1ull<<x))ro0.pb(i);
		else if(!a[i]&&c[i]&1ull<<x)r1.pb(i);
		else if(a[i]&&!(c[i]&1ull<<x))r0.pb(i);
		else ro1.pb(i);
		if(!b[i]&&!(d[i]&1ull<<x))co0.pb(i); 
		else if(!b[i]&&d[i]&1ull<<x)c1.pb(i);
		else if(b[i]&&!(d[i]&1ull<<x))c0.pb(i);
		else co1.pb(i);
	}
	if((r0.size()||r1.size())&&(c0.size()||c1.size()))
		if(r0.size()&&!r1.size()&&c0.size()&&!c1.size()){
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans[i][j]|=1ull<<x;
			for(int i=0;i<r0.size();i++)for(int j=1;j<=n;j++)(ans[r0[i]][j]|=1ull<<x)^=1ull<<x;
			for(int j=0;j<c0.size();j++)for(int i=1;i<=n;i++)(ans[i][c0[j]]|=1ull<<x)^=1ull<<x;
		}
		else if(!r0.size()&&r1.size()&&!c0.size()&&c1.size()){
			for(int i=0;i<r1.size();i++)for(int j=1;j<=n;j++)ans[r1[i]][j]|=1ull<<x;
			for(int j=0;j<c1.size();j++)for(int i=1;i<=n;i++)ans[i][c1[j]]|=1ull<<x;
		}
		else puts("-1"),exit(0);
	else if(r0.size()||r1.size())
		if(r0.size()&&r1.size()){
			for(int i=0;i<r1.size();i++)for(int j=1;j<=n;j++)ans[r1[i]][j]|=1ull<<x;
			for(int i=0;i<ro1.size();i++)ans[ro1[i]][1]|=1ull<<x;
		}
		else if(r0.size())
			if(!co1.size()||ro1.size())
				for(int i=0;i<ro1.size();i++)for(int j=1;j<=n;j++)ans[ro1[i]][j]|=1ull<<x;
			else if(ro0.size()>=2){
				for(int j=2;j<=n;j++)ans[ro0[0]][j]|=1ull<<x;
				for(int j=1;j<n;j++)ans[ro0[1]][j]|=1ull<<x;
			}
			else if(co1.size()<n&&ro0.size()==1){
				int notin=1,now=0;
				while(now<co1.size()&&co1[now]==notin)notin++,now++;
				for(int j=1;j<=n;j++)if(j!=notin)ans[ro0[0]][j]|=1ull<<x;
			}
			else puts("-1"),exit(0);
		else{
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans[i][j]|=1ull<<x;
			if(!co0.size()||ro0.size())
				for(int i=0;i<ro0.size();i++)for(int j=1;j<=n;j++)ans[ro0[i]][j]^=1ull<<x;
			else if(ro1.size()>=2){
				for(int j=2;j<=n;j++)ans[ro1[0]][j]^=1ull<<x;
				for(int j=1;j<n;j++)ans[ro1[1]][j]^=1ull<<x;
			}
			else if(co0.size()<n&&ro1.size()==1){
				int notin=1,now=0;
				while(now<co0.size()&&co0[now]==notin)notin++,now++;
				for(int j=1;j<=n;j++)if(j!=notin)ans[ro1[0]][j]^=1ull<<x;
			}
			else puts("-1"),exit(0);
		}
	else if(c0.size()||c1.size())
		if(c0.size()&&c1.size()){
			for(int j=0;j<c1.size();j++)for(int i=1;i<=n;i++)ans[i][c1[j]]|=1ull<<x;
			for(int j=0;j<co1.size();j++)ans[1][co1[j]]|=1ull<<x;
		}
		else if(c0.size())
			if(!ro1.size()||co1.size())
				for(int j=0;j<co1.size();j++)for(int i=1;i<=n;i++)ans[i][co1[j]]|=1ull<<x;
			else if(co0.size()>=2){
				for(int i=2;i<=n;i++)ans[i][co0[0]]|=1ull<<x;
				for(int i=1;i<n;i++)ans[i][co0[1]]|=1ull<<x;
			}
			else if(ro1.size()<n&&co0.size()==1){
				int notin=1,now=0;
				while(now<ro1.size()&&ro1[now]==notin)notin++,now++;
				for(int i=1;i<=n;i++)if(i!=notin)ans[i][co0[0]]|=1ull<<x;
			}
			else puts("-1"),exit(0);
		else{
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans[i][j]|=1ull<<x;
			if(!ro0.size()||co0.size())
				for(int j=0;j<co0.size();j++)for(int i=1;i<=n;i++)ans[i][co0[j]]^=1ull<<x;
			else if(co1.size()>=2){
				for(int i=2;i<=n;i++)ans[i][co1[0]]^=1ull<<x;
				for(int i=1;i<n;i++)ans[i][co1[1]]^=1ull<<x;
			}
			else if(ro0.size()<n&&co1.size()==1){
				int notin=1,now=0;
				while(now<ro0.size()&&ro0[now]==notin)notin++,now++;
				for(int i=1;i<=n;i++)if(i!=notin)ans[i][co1[0]]^=1ull<<x;
			}
			else puts("-1"),exit(0);
		}
	else
		if(n==1)
			if(ro0.size()&&co0.size());
			else if(ro1.size()&&co1.size())ans[1][1]|=1ull<<x;
			else puts("-1"),exit(0);
		else{
			for(int i=0;i<ro1.size();i++)ans[ro1[i]][ro1[i]==1?2:1]|=1ull<<x;
			for(int j=0;j<co1.size();j++)ans[co1[j]==1?1:2][co1[j]]|=1ull<<x;
		}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)cin>>d[i];
	for(int i=0;i<64;i++)sol(i);
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<ans[i][j]<<" ";puts("");}
	return 0;
}