//#include <bits/stdc++.h>
//#include <stdio.h>
#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<string.h>
#include<cmath>
#include<utility>
#include<functional>
#include<map>
#include<set>
#include<cctype>
#include<fstream>


#define FOR(i, a, b) for( int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for( int i=(a);i>=(b);i--)
#define LFOR(i, a, b) for( long long int i=(a);i<=(b);i++)
#define LRFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000 //2000000000
#define LLINF 1000000000000000000 //9000000000000000000
#define PI 3.14159265358979
#define MAXI 7500000

using namespace std;
typedef long long int ll;
typedef pair< long long int, long long  int> P;

int dy[5] = { 0,0,1,-1,0 };
int dx[5] = { 1,-1,0,0 ,0 };




long long int func(long long int n, long long int x,long long int size[],long long int pa[]) {
	if (x <= 0) {
		return 0;
	}
	if (n == 0) {
		return 1;
	}
	if (x <= size[n-1]+1) {
		return func(n - 1, x - 1, size,pa);
	}
	else if (x <=2*size[n-1]+2 ) {
		return func(n - 1, x - 1, size, pa) + 1 + func(n - 1, x - 2 - size[n - 1], size, pa);
	}
	else {
		return pa[n];
	}
}


int main(void) {
	long long int n, x;
	long long int size[51];
	long long int pa[51];

	cin >> n >> x;

	size[0] = 1;
	pa[0] = 1;
	FOR(i, 1, n) {
		size[i] = 2 * size[i - 1] + 3;
		pa[i] = 2 * pa[i - 1] + 1;
	}

	printf("%lld\n", func(n, x, size, pa));

	//cout << func(n,x,size,pa) << endl;

	

	return 0;
}