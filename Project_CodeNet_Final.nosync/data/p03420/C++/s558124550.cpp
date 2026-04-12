#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAXN 100000
#define ll long long
#define rint register int
#define gc() getchar()
inline int read(int r=0,int s=0,int c=gc()){for(;c<48||c>57;s=c,c=gc());for(;c>=48&&c<=57;(r*=10)+=c-48,c=gc());return s^'-'?r:-r;}
ll N, K, Ans; inline ll Calc(ll k)//{ll Ans = 0; for(ll b = k+1; b <= N; Ans += (N-k)/b+!!k, b++); return Ans;}
{ll Ans = 0; for(ll d = k+1, p; d <= N-k; p = (N-k)/((N-k)/d), Ans += (N-k)/d*(p-d+1), d = p+1); Ans += (N-k)*!!k; return Ans;}
int main()
{
	N = read(), K = read(); if(N < K) return puts("0"),0;
	for(ll k = K; k <= N-1; Ans += Calc(k), k++); cout << Ans <<endl; return 0;
}