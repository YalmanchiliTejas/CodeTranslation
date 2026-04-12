#include<bits/stdc++.h>

using namespace std;
typedef         long long int   ll;

#define         input           freopen("input.txt","r",stdin)
#define         output          freopen("output.txt","w",stdout)
#define         si(a)           scanf("%d",&a)
#define         sii(a,b)        scanf("%d%d",&a,&b)
#define         siii(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define         pi(a)           printf("%d",a)
#define         spc             printf(" ")
#define         bl              printf("\n")
#define         here(a)         printf("#### %d ####",a)
#define         pii             pair<int,int>
#define         fr(i,n)         for(int i=0;i<n;i++)
#define         case(num)       printf("Case %d:",num)
#define         inf             1000000050
#define         MAX             100010*3
#define         MOD             1000000007


long long int sum, sqrtsum,tmp,sqr;


int main(){

    //input;
    //output;


    sum = 0; sqrtsum = 0;

    int n;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>tmp;
        sum = (sum+tmp)%MOD;            /// a+b....

        sqr = (tmp*tmp)%MOD;           /// square
        sqrtsum = (sqrtsum+sqr)%MOD;   ///square sum
    }

    tmp = sum%MOD;
    sum = (tmp*tmp)%MOD;


    tmp = (sum - sqrtsum);
    if(tmp<0) tmp += MOD;

    //int m = bigMod(2,MOD-2);
    //cout<<m<<endl;

    //tmp = (tmp*m)%MOD;

    tmp = (tmp * 500000004)%MOD;


    cout<<tmp<<endl;

    return 0;
}
/**
*/
