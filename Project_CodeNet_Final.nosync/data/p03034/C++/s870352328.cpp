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
#include<iomanip>
#include<set>
#include "bits/stdc++.h"
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
typedef long double ld;
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
	int N;
	ll s[100001];
	ll ans=0;
	scan(N);
	rep(i,N){
		scan(s[i]);
	}
	rep1(C,(N-1)/2-1){
		ll sum=0;
		map<int,bool> alre;
		for(int k=1;C*k<N-1&&N-1-C*k-C>0&&alre[C*k]==0&&alre[N-1-C*k]==0&&C*k!=N-1-C*k;k++){
			sum+=s[C*k]+s[N-1-C*k];
			ans=max(sum,ans);
			alre[C*k]=1;
			alre[N-1-C*k]=1;
			//printf("C:%d k:%d A:%d B:%d plus:%lld,%lld  ans:%lld\n",C,k,N-1-C*k,N-1-C*k-C,C*k,N-1-C*k,sum);
		}
	}
	prin(ans);
	return 0;
}
