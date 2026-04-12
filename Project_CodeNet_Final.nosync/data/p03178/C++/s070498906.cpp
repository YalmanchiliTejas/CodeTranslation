#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<climits>

#define pii pair<int,int>
#define ll long long
#define MOD 1000000007
#define in2d(i,j,H,W)(0<=i&&i<H&&0<=j&&j<W)

using namespace std;
struct SegT{
	vector<ll>container;
	int n;
	void update(int i,ll x){
		int ii=i+n-1;
		container[ii]=x;
		while(ii>0){
			ii=(ii-1)/2;
			//////////////////////////////////////////
			container[ii]=max(container[2*ii+1],container[2*ii+2]);
			//////////////////////////////////////////
		}
	}
	ll get(int l,int r,int l2=0,int r2=-1,int k=0){
		if(r2==-1)r2=n;
		if(r2<=l||r<=l2)return 0;
		if(l<=l2&&r2<=r)return container[k];
		ll vl=get(l,r,l2,(l2+r2)/2,2*k+1);
		ll vr=get(l,r,(l2+r2)/2,r2,2*k+2);
		///////////////////////////
		return max(vl,vr);
		///////////////////////////
	}
	////////////////new///////////////////////
	SegT(vector<int> &A){
		n=pow(2,(int)log2(A.size())+1);
		container=vector<ll>(2*n,0);
		for(int i=0;i<A.size();i++)update(i,A[i]);
	}
	~SegT(){
		delete &container;
	}

};
string K;
int D;
int dp[10010][2][110];
int dfs(int k,int tight,int j){
	if(k==K.size())return j%D==0;
	if(dp[k][tight][j]!=-1)return dp[k][tight][j];
	int x=K[k]-'0';
	int r=(tight==1)?x:9;
	int ans=0;
	for(int i=0;i<=r;i++){
		int t;
		if(tight==0)t=0;
		else if(i==r)t=1;
		else t=0;
		ans+=dfs(k+1,t,(j+i)%D)%MOD;
		ans%=MOD;
	}
	return dp[k][tight][j]=ans%MOD;
}
int main(){
	cout<<fixed<<setprecision(11);
	cin>>K;
	cin>>D;
	for(int k=0;k<K.size();k++)for(int t=0;t<2;t++)for(int j=0;j<D;j++)dp[k][t][j]=-1;
	cout<<(dfs(0,1,0)+MOD-1)%MOD<<endl;
	return 0;
}

