#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
int n;
int a[6060];
int dp[2020][2020][3];
int mx[2020][2020][3];
int mx1[2020][3], mx2[2020][3];
int mx3[3];
int c[2020];
int s[2020];
int main()
{
    cin>>n;
    for(int i=0; i<3*n; i++){
        cin>>a[i]; a[i]--;
    }
    a[3*n]=a[3*n+1]=n;
    for(int i=1; i<=n; i++){
        if(a[3*i+1]==a[3*i] && a[3*i]==a[3*i-1]) c[i]++;
    }
    for(int i=0; i<=n; i++) s[i+1]=s[i]+c[i];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            for(int k=0; k<3; k++) dp[i][j][k]=-1, mx[i][j][k]=-n-1, mx1[i][k]=-n-1, mx2[i][k]=-n-1, mx3[k]=-n-1;
        }
    }
    dp[0][a[0]][0]=0;
    mx[a[1]][a[0]][0]=0;
    mx1[a[1]][0]=mx2[a[0]][0]=mx3[0]=0;
    int ans=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            for(int k=0; k<3; k++){
                int x1=-1, x2=-1;
                for(int l=0; l<3; l++){
                    if(l==k) continue;
                    if(x1==-1) x1=a[3*i+1-l];
                    else x2=a[3*i+1-l];
                }
                if(x1==x2){
                    for(int l=0; l<3; l++) dp[i][j][k]=max(dp[i][j][k], mx[j][x1][l]+s[i]+1);
                    for(int l=0; l<3; l++) dp[i][j][k]=max(dp[i][j][k], mx[x1][j][l]+s[i]+1);
                }
                for(int l=0; l<3; l++){
                    dp[i][j][k]=max(dp[i][j][k], mx1[j][l]+s[i]);
                    dp[i][j][k]=max(dp[i][j][k], mx2[j][l]+s[i]);
                }
                for(int l=0; l<3; l++){
                    if(k==l) continue;
                    if(a[3*i+1-l]!=j) continue;
                    for(int m=0; m<3; m++){
                        if(k==m || l==m) continue;
                        for(int p=0; p<3; p++) dp[i][j][k]=max(dp[i][j][k], mx[a[3*i+1-m]][a[3*i+1-m]][p]+s[i]+1);
                        for(int p=0; p<3; p++) dp[i][j][k]=max(dp[i][j][k], mx3[p]+s[i]);
                    }
                }
            }
        }
        for(int j=0; j<=n; j++){
            for(int k=0; k<3; k++){
                ans=max(ans, dp[i][j][k]);
                mx[a[3*i+1-k]][j][k]=max(mx[a[3*i+1-k]][j][k], dp[i][j][k]-s[i+1]);
                mx1[a[3*i+1-k]][k]=max(mx1[a[3*i+1-k]][k], dp[i][j][k]-s[i+1]);
                mx2[j][k]=max(mx2[j][k], dp[i][j][k]-s[i+1]);
                mx3[k]=max(mx3[k], dp[i][j][k]-s[i+1]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
