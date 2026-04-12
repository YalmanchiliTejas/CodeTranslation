//C - Sum of product of pairs
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

#define LL long long
#define Lowbit(X) (X&(-X))
#define Lson (X<<1)
#define Rson (X<<1|1)
#define Cl(X,Y) memset((X),(Y),sizeof(X))
#define FOR(i,A,B) for(LL i=A;i<=B;i++)
#define BOR(i,A,B) for(LL i=A;i>=B;i--)
#define FOR_SIDE(i,A) for(LL i=Head[A];i;i=Next[i])
#define INF 0x7fffffff
#define MOD 1000000007
using namespace std;
const LL MAXN=2e5+10;

LL Num[MAXN],Total,Ans,Pre[MAXN];

inline void File() {
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
}

int main() {
    //File();
	scanf("%lld",&Total);
	FOR(i,1,Total) {
		scanf("%lld",&Num[i]);
		Pre[i]=(Pre[i-1]+Num[i])%MOD;
	}
	FOR(i,1,Total-1) 
		(Ans+=(Num[i]*(Pre[Total]-Pre[i])%MOD)%MOD)%=MOD;
	cout<<(Ans%MOD+MOD)%MOD<<endl;
    //fclose(stdin); fclose(stdout);
    //system("pause");
    return 0;
}
