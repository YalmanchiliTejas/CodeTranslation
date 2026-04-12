//#include <bits/stdc++.h>
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

#define FOR(i,f,t) for(int i=(int)f; i<(int)t; i++)
#define FORR(i,f,t) for(int i=(int)f; i>(int)t; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define pb push_back
#define SYNC ios_base::sync_with_stdio(false)
#define inf 2248012
#define mp make_pair
#define F first
#define S second
#define ri(x) scanf("%d",&x)
#define rii(x,y) scanf("%d %d",&x,&y)
#define riii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define lri(x) scanf("%lld",&x)
#define lrii(x,y) scanf("%lld %lld",&x,&y)
#define lriii(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 5e5+3; //AREGLAAAAAAAAR!!!!
int a[MAXN],b[MAXN];
int main(){
	int n;
	ri(n);
	FOR(i,0,n){
		ri(a[i]);
	}
	int k=0,k2=n-1;
	
	for(int i=n-1; i>=0; i-=2){
		int i2=i-1;
		if(!i) i2=0;
		b[k]=a[i];
		b[k2]=a[i2];
		k++;
		k2--;
	}
	FOR(i,0,n) cout<<b[i]<<" ";
	cout<<endl;
}
