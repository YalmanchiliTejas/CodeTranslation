#include "bits/stdc++.h"

using namespace std;
using ll=long long;
using ull=unsigned long long;

typedef pair<int,int>Pi;
typedef pair<long long,long long>P;
typedef pair<long long,P>PP;
typedef pair<P,P>PPP;

const long long MOD=1e9+7;
const long long INF=5e18;
const int di[4]={1,0,-1,0};
const int dj[4]={0,1,0,-1};

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()

int n,a,b,c;
vector<int>v[100010];
int vis[100010],cnt[100010];


void input(){
	cin>>n;
	c=n;
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		a--,b--;
		v[a].eb(b);
		v[b].eb(a);
	}
	return;
}

void solve(){
	queue<int>q;
	for(int i=0;i<n;i++){
		cnt[i]=v[i].size();
		if(cnt[i]==1){
			q.push(v[i][0]);
		}
	}
	while(!q.empty()){
		int p=q.front();
		q.pop();
		if(vis[p])continue;
		vis[p]=1;
		int sum=0;
		for(int u:v[p]){
			if(cnt[u]==1){
				sum++;
				vis[u]=2;
			}
			cnt[u]--;
			cnt[p]--;
			if(cnt[u]==1){
				for(int x:v[u]){
					if(!vis[x]){
						q.push(x);
						break;
					}
				}
			}
		}
		if(sum>=2){
			cout<<"First"<<endl;
			return;
		}
	}
	for(int i=0;i<n;i++){
		if(vis[i]==2){
			for(int u:v[i]){
				if(vis[u]==1)vis[u]=3;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(vis[i]==1){
			cout<<"First"<<endl;
			return;
		}
	}
	cout<<"Second"<<endl;
	return;
}

int main(){
	input();
	solve();
	return 0;
}
