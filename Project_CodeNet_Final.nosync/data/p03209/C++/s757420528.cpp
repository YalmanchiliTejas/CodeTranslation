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
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
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
ll pati[51]={};
ll saizu[51]={};
ll patinum(ll N,ll X){
	if(N==0) return 1;
	else if(X==1) return 0;
	else if(1<X&&X<saizu[N-1]+2){
		return patinum(N-1,X-1);
	}
	else if(X==saizu[N-1]+2){
		return pati[N-1]+1;
	}
	else if(saizu[N-1]+2<X&&X<saizu[N]){
		return patinum(N-1,X-(saizu[N-1]+2))+pati[N-1]+1;
	}
	else{
		return pati[N];
	}
}
int main(){
	ll N,X;
	scan(N);scan(X);
	saizu[0]=1;
	pati[0]=1;
	rep(i,N){
		pati[i+1]=pati[i]*2+1;
		saizu[i+1]=saizu[i]*2+3;
	}
	prin(patinum(N,X));
	return 0;
}
