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
#define         MAX             100010*2
#define         MOD             1000000007

vector<ll>v,val;

int main(){

    //input;
    //output;

    ll sum,n,tmp;
    cin>>n;
    sum = 0;

    for(int i=0;i<n;i++){
        cin>>tmp;
        sum += tmp;
        v.push_back(sum);
        val.push_back(tmp);
    }

    ll ans = 0;

    for(int i=0;i<(n-1);i++){
        ans = (ans + ((v[n-1]-v[i])%MOD * val[i])%MOD)%MOD;
    }


    cout<<ans<<endl;


    return 0;
}
/**
*/
