#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 1000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
char str[N][N];
int bucket[N][27];
int vis[27];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",str[i]+1);
        int len=strlen(str[i]+1);
        for(int j=1;j<=len;j++){
            int temp=str[i][j]-'a'+1;
            bucket[i][temp]++;
        }
    }
 
    for(int i=1;i<=26;i++)
        vis[i]=bucket[1][i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=26;j++){
            vis[j]=min(vis[j],bucket[i][j]);
        }
    }
    
    for(int i=1;i<=26;i++){
        while(vis[i]--){
            char temp=(char)(i+'a'-1);
            printf("%c",temp);
        }
    }
    
    return 0;
}