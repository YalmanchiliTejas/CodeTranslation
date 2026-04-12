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
ll dp[3001][3001];//dp[l][r]:左端が l 枚目，右端が r 枚目の状態から始めた時の，(先手の得点) - (後手の得点) の最大値（手番が先手の時）または最小値（手番が後手の時）
ll coef(int i,int j,int N){
	return (N-(j-i+1))%2*2-1;
}
int main(){
	int N;
	ll a[3001];
	scan(N);
	rep(i,N){
		scan(a[i]);
	}
	rep(k,N){
		rep(i,N-k){
		int j=i+k;
			if(j==i) dp[i][j]=-coef(i,j,N)*a[i];
			else{
				if(coef(i,j,N)==-1){
					dp[i][j]=max(dp[i+1][j]-coef(i,j,N)*a[i],dp[i][j-1]-coef(i,j,N)*a[j]);
				}
				else{
					dp[i][j]=min(dp[i+1][j]-coef(i,j,N)*a[i],dp[i][j-1]-coef(i,j,N)*a[j]);
				}
			}
		}
	}
	prin(dp[0][N-1]);
	return 0;
}
