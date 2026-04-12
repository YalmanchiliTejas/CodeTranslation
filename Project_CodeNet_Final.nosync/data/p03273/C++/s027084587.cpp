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
int main(){
	int H,W;
	char a[101][101];
	bool oki[101]={},okj[101]={};
	scan(H);scan(W);
	rep(i,H){
		scan(a[i]);
	}
	rep(i,H){
		bool flag=0;
		rep(j,W){
			if(a[i][j]=='#') flag=1;
		}
		oki[i]=flag;
	}
	rep(j,W){
		bool flag=0;
		rep(i,H){
			if(a[i][j]=='#') flag=1;
		}
		okj[j]=flag;
	}
	rep(i,H){
		if(oki[i]){
			rep(j,W){
				if(okj[j]) printf("%c",a[i][j]);
			}
			kaigyo;
		}
	}
	return 0;
}
