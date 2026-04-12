#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define LL long long
#define FOR(i,j,k) for(LL (i) = j;(i) <= (k);i++)
using namespace std;
const LL MaN=1e5+10;
LL N,X,M,Ans;
LL Loc[MaN],Pre[MaN];
signed main() {
    cin>>N>>X>>M;
    Ans+=X;
    Pre[1]=X; 
    Loc[X]=1;
    LL Sta=INF;
    FOR(i,2,N) {
        X=X*X%M;
        Pre[i]=Pre[i-1]+X;
        Ans+=X;
        if(Loc[X]) { 
			LL Len=i-Loc[X]; 
			Ans+=(N-i)/Len*(Pre[i]-Pre[Loc[X]]); 
			Sta = N - ( N - i ) % Len+1; 
			break; 
		}
        else Loc[X]=i;
    }
    FOR(i,Sta,N) {
        X = X * X % M;
        Ans += X;
    }
    cout << Ans << endl;
    return 0;
}