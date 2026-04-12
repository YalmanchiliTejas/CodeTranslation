#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define FORq(i, m, n) for(int i = m;i <= n;i++)
#define SCD(n) scanf("%d",&n)
#define SCD2(m,n) scanf("%d%d",&m,&n)
#define SCD3(m,n,k) scanf("%d%d%d",&m,&n,&k)
#define PB push_back
#define MP make_pair
#define ARSCD(A,N) REP(i,N){SCD(A[i]);}
#define ARSCD1(A,N) FORq(i,1,N){SCD(A[i]);}
#define PRINTD(n) printf("%d\n",n)
#define PRINTLLD(n) printf("%lld\n",n);
#define DEBUG printf("%s\n","debug")
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
//////////////////////////////////////////////////////

int main(){
	int price = 0;
	int A,B,C,X,Y;
	scanf("%d%d%d%d%d",&A,&B,&C,&X,&Y);
	
	int minab = min(X,Y);

	int mina = min(A,2*C);
	int minb = min(B,2*C);
	int abset = min(2*C,A+B);
	
	X = X - minab;
	Y = Y - minab;
	
	price = price + (minab * abset);
	

	
	price += (X * mina) + (Y*minb);
	
	PRINTD(price);
	
	
}








