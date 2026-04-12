//marico el que lo lea
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define FOR(i,f,t) for(int i=f; i<(int)t; i++)
#define FORR(i,f,t) for(int i=f; i>(int)t; i--)
#define pb push_back
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ms2(obj, val, sz) memset(obj, val, sizeof(obj[0])*sz)
#define ri(x) scanf("%d",&x)
#define rl(x) scanf("%lld",&x)
#define rii(x,y) ri(x), ri(y)
#define rll(x,y) rl(x), rl(y)

#define fst first
#define snd second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;

const int MAXN = 2e5+5;

deque<int> dq;
int n;

int main(){
	bool rev=false;
	ri(n);
	FOR(i,0,n){
		int a; ri(a);
		if(rev) dq.push_front(a);
		else dq.push_back(a);
		rev = !rev;
	}
	if(rev){
		FORR(i,n-1,-1) printf("%d ",dq[i]);
	}else{
		FOR(i,0,n) printf("%d ",dq[i]);
	}
	printf("\n");
}