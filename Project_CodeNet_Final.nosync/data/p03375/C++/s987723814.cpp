#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=3005;
int n,ans,mo;
int s[N][N],c[N][N];
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
int ksm2(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%(mo-1))if(y&1)t=(ll)t*x%(mo-1);
	return t;
}
int main(){
	cin>>n>>mo;
	s[0][0]=1;
	fo(i,1,n){
		s[i][0]=1;
		fo(j,1,i)s[i][j]=((ll)s[i-1][j]*(j+1)+s[i-1][j-1])%mo;
	}
	
	fo(i,0,n){
		c[i][0]=1;
		fo(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
	}
	fo(a,0,n){
		int x=ksm(2,a),y=ksm(2,ksm2(2,a)),tot=0,g=1;
		fo(i,0,n-a){
			tot=((ll)s[n-a][i]*g+tot)%mo;
			g=(ll)g*x%mo;
		}
		ans=((ll)y*tot%mo*c[n][a]*(n-a&1?-1:1)+ans)%mo;
	}
	printf("%d",(ans+mo)%mo);
}