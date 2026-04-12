#include<stdio.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define VgetI(n) int (n); scanf("%d",&(n))
#define VgetII(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define VgetIII(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define INF 2000000000
#define PI 3.1415926535897932384626
const ll MOD=1e9+7;
int main(){
        int n,m;
        while(~getII(n,m)){
                printf("%s\n",n==m?"Yes":"No");
        }
}