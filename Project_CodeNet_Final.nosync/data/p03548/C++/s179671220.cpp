#include<iostream>
#include<climits>
#include<math.h>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<stdio.h>
#include <string>
#include <complex>
#include <functional>
using namespace std;
using ll = long long;
//typedef pair<string,string> P;
//double dat[100][100];
//int dp[6][1010];//動的計画法
//int prime[10000001];
//char str[1010][1010];
//vector<pair<int,int> > pc[100001];
//int ABS(int a){return max(a,-a);}
//long long num[100000];
int main(){
	ll x,y,z,ans;
	cin>>x>>y>>z;
	for(int i=x/y;i>=0;i--){
		if((y*i+z*(i+1))<=x){
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}