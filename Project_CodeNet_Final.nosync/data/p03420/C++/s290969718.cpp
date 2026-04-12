//#include <bits/stdc++.h>
#include<iostream>
#include<stdio.h>
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


int main(void) {
	int n, k;
	long long int count = 0;
	int p;

	cin >> n >> k;

	FOR(i, 1, n) {
		if (k >= i) {
			continue;
		}
		else {
			p = n / i;
			count += p * (i - k);
			if (p*i < n) {
				if (k == 0) {
					count += n - (p*i + 1) + 1;
				}
				else {
					if (n - (p*i + k) + 1 >= 0) {
						count += n - (p*i + k) + 1;
					}
					
				}
			}
			
			
			//cout << i << " " << count << endl;
		}
	}

	cout << count << endl;

	return 0;
}