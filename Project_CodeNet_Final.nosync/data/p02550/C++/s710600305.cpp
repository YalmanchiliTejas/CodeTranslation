//E - Sequence Sum
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

#define LL long long
#define Cl(X,Y) memset((X),(Y),sizeof(X))
#define FOR(i,A,B) for(LL i=A;i<=B;i++)
#define BOR(i,A,B) for(LL i=A;i>=B;i--)
#define Lowbit(X) (X & (-X))
#define INF 0x3f3f3f3f3f3f3f3f
#define Rson (X<<1|1)
#define Lson (X<<1)
using namespace std;
const LL MaxN=1e5+10;

LL N,X,M,Ans;
LL Loc[MaxN],Pre[MaxN];

inline void File() {
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
}
signed main() {
    // File();
    ios::sync_with_stdio(false);
    cin>>N>>X>>M;
    Ans+=X;
    Pre[1]=X; 
    Loc[X]=1;
    LL Sta=INF;
    FOR(i,2,N) {
        X=X*X%M;
        Pre[i]=Pre[i-1]+X;
        Ans+=X;
        if(Loc[X]) { LL Len=i-Loc[X]; Ans+=(N-i)/Len*(Pre[i]-Pre[Loc[X]]); Sta=N-(N-i)%Len+1; break; }
        else { Loc[X]=i; }
    }
    FOR(i,Sta,N) {
        X=X*X%M;
        Ans+=X;
    }
    cout<<Ans<<endl;
    // fclose(stdin);
    // fclose(stdout);
   // system("pause");
    return 0;
}