#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int a,b,ab,na,nb;
    while(~scanf("%d%d%d%d%d",&a,&b,&ab,&na,&nb))
    {
        int m1,m2,m3;
        m1=na*a+nb*b;
        m3=2*ab*max(na,nb);
        if(na>nb)   m2=ab*(nb)*2+(na-nb)*a;
        else    m2=ab*(na)*2+(nb-na)*b;
        printf("%d",min(min(m1,m3),m2));
    }
    return 0;
}
