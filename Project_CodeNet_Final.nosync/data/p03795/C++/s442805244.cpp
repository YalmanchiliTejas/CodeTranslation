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
typedef pair<int,int> P;
double dat[100][100];
//int dp[6][1010];//動的計画法
int prime[10000001];
char str[1010][1010];
vector<pair<int,int> > pc[100001];
int ABS(int a){return max(a,-a);}
const int nmax=40,abmax=10,inf = 1000000;

 int a[nmax],b[nmax],c[nmax];
 int dp[nmax+1][nmax*abmax+1][nmax*abmax+1];
int main(){
	int n;
	int x,y;
	cin>>n;
	y=n/15;
	cout<<800*n-200*y<<endl;
	return 0;
}