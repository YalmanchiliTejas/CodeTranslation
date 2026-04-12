#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#include<bitset>
#include<iomanip>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
vint adj[100001];
int color[100001],d[100001],f[100001],tt;
bool matched[100001]={};
void dfs_visit(int u){
	color[u]=1;
	d[u]=tt;
	tt++;
	rep(i,adj[u].size()){
		int v=adj[u][i];
		if(color[v]==0){
			dfs_visit(v);
			if(matched[u]==false&&matched[v]==false){
				matched[u]=matched[v]=true;
			}
		}
	}
	color[u]=2;
}
int main(){
	int N;
	int A[100001],B[100001];
	int edgecount[100001]={};
	int flag=1;
	scan(N);
	rep(i,N-1){
		scan(A[i]);scan(B[i]);
		A[i]--;B[i]--;
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
		edgecount[A[i]]++;
		edgecount[B[i]]++;
	}
	rep(i,N){
		color[i]=0;
	}
	tt=0;
	rep(i,N){
		if(edgecount[i]==1){
			dfs_visit(i);
			break;
		}
	}
	rep(i,N){
		//printf("%d d:%d matched:%d\n",i+1,d[i],matched[i]);
		if(matched[i]==false) flag=0;
	}
	if(flag) prin("Second");
	else prin("First");
	return 0;
}
