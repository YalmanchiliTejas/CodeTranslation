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
typedef string::const_iterator State;

int dy[5] = { 0,0,1,-1,0 };
int dx[5] = { 1,-1,0,0 ,0 };




int main(void) {
	
	long long int k, a, b;
	long long int now = 0;
	long long int count = -1;

	cin >> k >> a >> b;

	now += a;

	if (a - b <= 0) {
		count = -1;
	}
	if (now >= k) {
		count = 1;
	}
	else if(a-b>0) {
		b = a - b;
		if ((k - now) % b == 0) {
			count = ((k - now) / b) * 2 + 1;
		}
		else {
			count = ((k - now) / b + 1) * 2 + 1;
		}

	}
	cout << count << endl;
	

	

	return 0;
}