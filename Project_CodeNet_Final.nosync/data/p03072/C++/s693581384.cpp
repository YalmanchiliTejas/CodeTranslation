#include<bits/stdc++.h>
using namespace std;
#define     siii(a,b,c)       scanf("%d%d%d",&a,&b,&c)
#define     si(a)             scanf("%d",&a)
#define     sii(a,b)          scanf("%d%d",&a,&b)
#define     sl(a)             scanf("%lld",&a);
#define     sll(a,b)          scanf("%lld%lld",&a,&b);
#define     slll(a,b,c)       scanf("%lld%lld%lld",&a,&b,&c);
#define     sd(a)             scanf("%lf",&a);
#define     sdd(a,b)          scanf("%lf%lf",&a,&b);
#define     pb(a)             push_back(a)
#define     deb(a)            printf("### %d ###\n",a)
#define     mp                make_pair
#define     pf                printf
#define     fl(a, b, c)       for(int a= b ;a<c;a++)
#define     mx                100000 //10^5
#define     fread             freopen("input.txt","r",stdin)
#define     CLR(a,b)          memset(a,b,sizeof(a))
#define     ll                long long
#define     D(x)              cout<<#x" = "<<x<<endl;
#define     sz                10000
#define     bl                printf("\n")
#define     spc               printf(" ")


int main()
{
    int n;
    si(n);
    vector<int>h(n);
    fl(i,0,n) si(h[i]);
    int ans  = 0;
    //for(int i = 0 ; i< n ; i++) D(i);
    fl(i,0,n)
    {
        bool ck = true;
        fl(j,0,i)
        {
            if(h[j]>h[i])
            {
                ck = false;
                break;
            }
        }
        if(ck)
        {
            ++ans;
        }
    }
    cout<<ans<<endl;



    return 0;
}
