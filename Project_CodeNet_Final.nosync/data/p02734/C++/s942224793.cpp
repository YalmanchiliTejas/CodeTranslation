//Aleksander Łukasiewicz
#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int INF = 1000000009;
const int MAXN = 3000;
const int MOD = 998244353;

int dp[MAXN + 3];
int tab[MAXN + 3];

int main(){
    int n, s;
    scanf("%d %d", &n, &s);
    for(int i=1; i<=n; i++)
        scanf("%d", &tab[i]);
    int ans = 0;
    for(int i=1; i<=n; i++){
        dp[0] = i;
        for(int j=s; j>=tab[i]; j--){
            dp[j] += dp[j-tab[i]];
            if(dp[j] >= MOD) dp[j] -= MOD;
        }
        
        ans += dp[s];
        if(ans >= MOD) ans -= MOD;
    }
    
    printf("%d\n", ans);
    
return 0;
}