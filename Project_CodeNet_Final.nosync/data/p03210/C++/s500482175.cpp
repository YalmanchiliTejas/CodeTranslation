#include<bits/stdc++.h>
using namespace std;
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?(-x):x)
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define RF(i,L,R) for (int i = L; i > R; i--)
#define RFE(i,L,R) for (int i = L; i >= R; i--)
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define VgetI(n) int (n); scanf("%d",&(n))
#define VgetII(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define VgetIII(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define ll long long
#define INF 1000000000000000005
#define nINF -2000000000
#define MOD 1e9+7
#define PI 3.1415926535897932384626
int main(){
	int n;
	while(~getI(n)) printf("%s\n",(n==3||n==5||n==7)?"YES":"NO");
}
