#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

typedef long long LL;

LL nall[55];
LL p1[55];

LL h1(int n,LL k)
{
    LL ans =0;
    if (k == 0)
        return 0;
    if (n == 0)
        return 1;

    if (k >= 1+nall[n-1])
        ans += p1[n-1];
    else
    {
        //cout<<n<<' '<<k<<' '<<ans<<"break"<<endl;
        return h1(n-1,k-1);
    }
    if (k >= 2+nall[n-1])
        ans ++;
    if (k >= 3+nall[n-1])
        ans += h1(n-1,k-nall[n-1]-2);
    //cout<<n<<' '<<k<<' '<<ans<<endl;
    return ans;
}


int main()
{
    
    LL k=1;
    LL p=1;
    nall[0] =1;
    p1[0] =1;
    for (int i=1; i<=50; i++)
    {
        k *=2;
        p *=2;
        ++p;
        k+=3;
        nall[i] = k;
        p1[i] = p;
        //cout<<k<<' '<<p<<endl;
    }
    LL N,K;
    cin>>N>>K;
    cout<<h1(N,K)<<endl;





#ifdef VSCode
    system("pause");
#endif
    return 0;
}