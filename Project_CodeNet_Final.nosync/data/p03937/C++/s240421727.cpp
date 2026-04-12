//*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <functional>
#define MOD 1000000007
#define MAX 0x3f3f3f3f
#define MAX2 0x3f3f3f3f3f3f3f3fll
#define ERR 1e-10
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int n, m;
char a[10][10];

int check[10][10];

int main()
{
	int i, j, k, l;
	cin>>n>>m;
	int cnt=0;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++) for(j=0;j<m;j++) cnt+=a[i][j]=='#';
	int nowx=0, nowy=0;
	while(nowx != n-1 || nowy != m-1)
	{
		if(nowy != m-1 && a[nowx][nowy+1] == '#') nowy++;
		else if(nowx != n-1 && a[nowx+1][nowy] == '#') nowx++;
		else break;
	}
	if(nowx == n-1 && nowy == m-1 && cnt == n+m-1) cout<<"Possible";
	else cout<<"Impossible";
	cout<<endl;
	return 0;
}
//*/