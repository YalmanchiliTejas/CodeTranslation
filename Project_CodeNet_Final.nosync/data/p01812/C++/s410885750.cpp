#include<bits/stdc++.h>
using namespace std;


int main(){
int n,m,k;
cin>>n>>m>>k;
vector<int> d(m);
vector<vector<int> > v(n,vector<int>(k));
vector<int> nogoal(n,-1);
for(int i=0;i<m;i++){
	cin>>d[i];
	d[i]--;
	nogoal[d[i]]=i;
}
for(int i=0;i<n;i++)for(int j=0;j<k;j++){
	cin>>v[i][j];
	v[i][j]--;
}
vector<int> dp(1<<m,-1);
queue<int> q;
q.push((1<<m)-1);
dp[(1<<m)-1]=0;

while(!q.empty()){
	int now=q.front();
	q.pop();
//	cout<<now<<dp[now]<<endl;
	if(now==0)break;
	for(int i=0;i<k;i++){
	int next=0;
		for(int j=0;j<m;j++){
			if(now&(1<<j))
			if(nogoal[v[d[j]][i]]>=0){
			next=next|(1<<nogoal[v[d[j]][i]]);
			}
		}	
	if(dp[next]<0){
		dp[next]=dp[now]+1;
		q.push(next);
	}
	
	else if(dp[next]>dp[now]+1){
	dp[next]=dp[now]+1;
		q.push(next);
	}
		

	}

}


cout<<dp[0]<<endl;
return 0;
}

