#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a; i<n; i++)
#define rloop(i,a,n) for(int i=a; i>=n; i--)
#define lli long long int
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ff first
#define ss second
#define pb push_back

lli dp[3001][3001];
bool visited[3001][3001];

lli func(lli v[],int beg,int end,int cnt){
	if(visited[beg][end]!=0)
		return dp[beg][end];
	else if(beg==end)
	{
		if(cnt%2)
			return v[beg];
		else{
			return v[beg]*(-1);
		}
	}
	else{
		visited[beg][end]=1;
		if(cnt%2){
			dp[beg][end]=max(v[beg]+func(v,beg+1,end,cnt+1),v[end]+func(v,beg,end-1,cnt+1));
		}
		else{
			dp[beg][end]=min((-1*v[beg])+func(v,beg+1,end,cnt+1),(-1*v[end])+func(v,beg,end-1,cnt+1));
		}
		return dp[beg][end];
	}
}

int main(){
	int n;
	cin>>n;

	lli v[n+1];

	loop(i,1,n+1){
		cin>>v[i];
	}

	cout<<func(v,1,n,1);
}