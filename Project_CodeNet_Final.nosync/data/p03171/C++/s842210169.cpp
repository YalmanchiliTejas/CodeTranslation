#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

#pragma GCC optimize("O3")
#define MOD 1000000007
#define pb push_back
#define fi first
#define se second
#define fr front()
#define ba back()
#define tp top()
#define mem(x,n) memset(x,n,sizeof(x));
#define sz(x) (int)((x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,l) for(auto it=l.begin();it!=l.end();it++)
#define pnl printf("\n")
#define len(x) x.length()

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL,LL> pii;
typedef pair<pii,int> piii;
const int inf=(1<<30);
const LL llinf=(1ll<<60);
const double eps=(1e-10);
//const double pi=2*acos(0.0);
//const double GOLD=((1+sqrt(5))/2);
const int xx[8]={1,0,-1,0,1,-1,1,-1};
const int yy[8]={0,1,0,-1,-1,1,1,-1};
const int kx[8]={1,1,2,2,-1,-1,-2,-2};
const int ky[8]={2,-2,1,-1,2,-2,1,-1};

/* \( ·w·)~ Clapie ~(·w· )/ */

LL memo[3005][3005][2],arr[3005];
int n;

LL dp(int left,int right,int person){
	//0 taro max
	//1 jiro min
	
	if(left>right) return 0;
	if(memo[left][right][person]!=-1) return memo[left][right][person];
	
	if(person==0){
		return memo[left][right][person]=max(dp(left+1,right,1-person)+arr[left],dp(left,right-1,1-person)+arr[right]);
	}
	else{
		return memo[left][right][person]=min(dp(left+1,right,1-person)-arr[left],dp(left,right-1,1-person)-arr[right]);
	}
}

int main(){
	mem(memo,-1);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	LL ans=dp(0,n-1,0);
	printf("%lld\n",ans);
}