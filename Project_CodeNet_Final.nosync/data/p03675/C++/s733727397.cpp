#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define pb push_back
#define ri(x) scanf("%d",&x)
#define rii(x,y) ri(x),ri(y)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ms2(obj,val,sz) memset(obj,val,sizeof(obj[0])*sz)
#define FOR(i,f,t) for(int i=f;i<(int)t;i++)
#define FORR(i,f,t) for(int i=f;i>(int)t;i--)

typedef long long ll;
typedef vector<int> vi;

const int MAXN=2e5;

int N,A[MAXN],B[MAXN],j;

int main() {
	ri(N);
	FOR(i,0,N) ri(A[i]);
	j = N-1;
	FOR(i,0,(N+1)/2) B[i] = A[j], j-=2;
	j = 1 - (N%2 == 0);
	FOR(i,(N+1)/2,N) B[i] = A[j], j+=2;
	FOR(i,0,N) printf("%d ",B[i]);
	printf("\n");
}
