//A - Air Conditioner
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
using namespace std;

inline void File() {
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
}

int main() {
    //File();
    int X;
    scanf("%d",&X);
    if(X>=30) { printf("Yes\n"); }
    else printf("No\n");
    //fclose(stdin); fclose(stdout);
   // system("pause");
    return 0;
}