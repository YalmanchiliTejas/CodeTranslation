#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<cstring>
#include<map>
 
 
using namespace std;
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007

int A,B,C,X,Y;
signed main(){
    
    scanf("%lld %lld %lld %lld %lld",&A,&B,&C,&X,&Y);
    int ans=0;
    if(2*C<A+B){
        ans=min(X,Y)*2*C;
        if(X-min(X,Y)>0){//Aがもう少し必要
            if(A<2*C)ans+=A*(X-min(X,Y));//一枚ずつ買う
            else ans+=2*C*(X-min(X,Y));
        }
        if(Y-min(X,Y)>0){
            if(B<2*C)ans+=B*(Y-min(X,Y));//一枚ずつ買う
            else ans+=2*C*(Y-min(X,Y));
        }
    }else{
        ans=X*A+Y*B;
    }
    printf("%lld\n",ans);
    return 0;
}
