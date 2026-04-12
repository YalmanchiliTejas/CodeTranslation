#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define mod 1000000007 //10^9+7
#define INF 1000000000000 //10^12
#define P pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
int h,w;
char a[10][10];
bool ans=true;
signed main(){
    cin>>h>>w;
    rep(i,h){
        rep(j,w){
            cin>>a[i][j];
        }
    }
    rep(i,h){
        rep(j,w){
            if(a[i][j]=='.')continue;
            if(i==0&&j==0){
                if(a[i+1][j]==a[i][j+1])ans=false;
            }
            else if(i==0&&j==w-1){
                if(a[i+1][j]=='.'||a[i][j-1]=='.')ans=false;
            }
            else if(i==h-1&&j==0){
                if(a[i-1][j]=='.'||a[i][j+1]=='.')ans=false;
            }
            else if(i==h-1&&j==w-1){
                if(a[i-1][j]==a[i][j-1])ans=false;
            }
            else if(i==0){
                if(a[i][j-1]=='.'||a[i][j+1]==a[i+1][j])ans=false;
            }
            else if(i==h-1){
                if(a[i-1][j]==a[i][j-1]||a[i][j+1]=='.')ans=false;
            }
            else if(j==0){
                if(a[i-1][j]=='.'||a[i][j+1]==a[i+1][j])ans=false;
            }
            else if(j==w-1){
                if(a[i][j-1]==a[i-1][j]||a[i+1][j]=='.')ans=false;
            }
            else{
                if(a[i+1][j]==a[i][j+1]||a[i-1][j]==a[i][j-1])ans=false;
            }
        }
    }
    if(ans)puts("Possible");
    else puts("Impossible");
    return 0;
}
