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
int main(){
	int H,W;
	char A[10][10];
	scan(H);scan(W);
	int l=0;
	int ans=1;
	rep(i,H){
		scan(A[i]);
		rep(j,W){
			if(A[i][j]=='#'){
				if(j<l) ans=0;
				l=max(j,l);
			}
		}
	}
	if(ans) prin("Possible");
	else prin("Impossible");
	return 0;
}
