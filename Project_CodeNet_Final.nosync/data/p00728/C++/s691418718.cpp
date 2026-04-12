#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define CHMIN(a,b) (a) = min((a),(b))
#define CHMAX(a,b) (a) = max((a),(b))

int main()
{
    int in;
    int num;
    int ans=0;
    int point[105]={};
    while(1==1)
    {
        
        scanf("%d\n",&in);
        if(in==0)return 0;
        num=in;
        ans=0;
        REP(i,num)
        {
            scanf("%d\n",&point[i]);
            ans+=point[i];
        }
        sort(&point[0],&point[num]);
        ans-=(point[0]+point[num-1]);
        printf("%d\n",ans/(num-2));
    }
    return 0;
}
