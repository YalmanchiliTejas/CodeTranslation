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
int main(){
	int N,M;
	int a[100],b[100];
	bool miti[9][9]={};
	scan(N);scan(M);
	rep(i,M){
		scan(a[i]);scan(b[i]);
		miti[a[i]][b[i]]=true;
		miti[b[i]][a[i]]=true;
	}
	vint p;
	int ans=0;
	rep1(i,N) p.push_back(i);
	while(1){
		if(p[0]!=1) break;
		int flag=1;
		rep(i,p.size()-1){
			if(miti[p[i]][p[i+1]]==false){
				flag=0;
			}
		}
		ans+=flag;
		next_permutation(p.begin(),p.end());
	}
	prin(ans);


	return 0;
}
