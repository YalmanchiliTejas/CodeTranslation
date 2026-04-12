#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#include<cstdlib>
#include<ctime>
#define rep(i,j,k) for(register int i = j; i <= k; i++)
#define dow(i,j,k) for(register int i = j; i >= k; i--)
#define ll long long
#define mp make_pair
using namespace std;
 
inline int read() {
	int s = 0, t = 1; char c = getchar();
	while( !isdigit(c) ) { if( c == '-' ) t = -1; c = getchar(); }
	while( isdigit(c) ) s = s * 10 + c - 48, c = getchar();
	return s * t;	
} 

const int N = 2e5+5;
int v[N], ans[N];

int main() {
	int n = read();
	rep(i,1,n) v[i] = read(); 
	int l = 1, r = n, tot = n;
	while( tot ) { 
		ans[l++] = v[tot--];
		if( tot ) ans[r--] = v[tot--];
	}
	rep(i,1,n) cout<<ans[i]<<" "; cout<<endl;
    return 0;
} 