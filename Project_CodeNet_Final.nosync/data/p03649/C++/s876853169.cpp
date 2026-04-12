#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<set>
#include<list> 
#include<string>
#include<cstring>
#include<cmath>

#define vint vector<int>
#define vstr vector<string>
#define vll vector<long long>
#define ll long long
#define pf printf
#define sf scanf
#define sfd(n) scanf("%d", &n)
#define pfd(n) printf("%d", n);
#define pft	printf("\t")
#define pfn printf("\n")
#define pfk printf(" ")
#define N 200010
#define PI 3.1415926

using namespace std;

int main() {
	int n;
	sfd(n);
	ll* num = new ll[n];
	for( int i=0; i<n; i++ ) {
		sf("%lld", &num[i]);
	}
	ll cnt = 0;
	while( 1 ) {
		ll max = num[0];
		int pos = 0; 
		for( int i=0; i<n; i++ ) {
			if( max<num[i] ) {
				max = num[i];
				pos = i;
			}
		}
		if( num[pos]<n ) {
			break;
		}
		for( int i=0; i<n; i++ ) {
			if( i==pos ) {
				num[i] = max%n;
			}else {
				num[i] += max/n;
			}
		}
		cnt += max/n;
	}
	pf("%lld", cnt);
	
	return 0;
}
