#include <iostream>
#define SM 3005
using namespace std;
long long n, a[SM], F[SM][SM][3];
long Try(long L, long R, int x)
    {
        if (L>R) return 0;
        if (F[L][R][x]!=0) return F[L][R][x];
        if(x==1)
        {
            F[L][R][x]=Try(L+1,R,(x+1)%2)+a[L];
            F[L][R][x]=max(F[L][R][x],Try(L,R-1,(x+1)%2)+a[R]);
        }
        else
        {
            F[L][R][x]=Try(L+1,R,(x+1)%2)-a[L];
            F[L][R][x]=min(F[L][R][x],Try(L,R-1,(x+1)%2)-a[R]);
        }
        return F[L][R][x];
    }
int main()
    {
        long long i,j,x;
        cin>>n;
        for (i=1;i<=n;++i) cin>>a[i];
        cout<<Try(1,n,1);
        return 0;
    }
