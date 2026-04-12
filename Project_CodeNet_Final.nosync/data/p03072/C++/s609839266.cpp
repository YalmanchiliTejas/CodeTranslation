#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
 
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define LLIandI pair<long long int , int>
#define ll long long

int main(void){
    int N;
    scanf("%d",&N);
    int H[22];
    int high=0;
    int ans=0;
    rep(i,N){
        scanf("%d",&H[i]);
        if(H[i]>=high){
            high=H[i];
            ans++;
        }
    }
    printf("%d\n",ans);
}
