#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAX 3010
ll dp[MAX][MAX];
ll v[MAX];
bool been[MAX][MAX];
ll f(int i,int j){
    if(i > j) return 0;
    if(been[i][j]) return dp[i][j];
    been[i][j] = true;
    return dp[i][j] = max(v[i]-f(i+1,j),v[j]-f(i,j-1));
}
int main(){
    memset(been,false,sizeof(been));
    int n;cin >> n;
    for(int i = 0;i<n;i++) cin >> v[i];
    cout << f(0,n-1) << '\n';
    return 0;
}