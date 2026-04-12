#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
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

char S[10];


signed main(){
    scanf("%s",&S);
    for(int i=1;i<3;i++){
        if(S[i]!=S[i-1]){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
