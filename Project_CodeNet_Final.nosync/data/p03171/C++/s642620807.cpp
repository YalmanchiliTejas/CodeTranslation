#include<bits/stdc++.h>
using namespace std;
#define mods 1000000007
#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef long long int lint;
typedef unsigned long long int ulint;
 
lint n,dizi[3020],dp[3020][3020];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lint i,j,k,l,il;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>dizi[i];
        }
        il=0;
    for(j=n;j>0;j--,il++){
        for(i=1;i<=j;i++){
            
            if(j%2==0){
                if(j==n){
                    dp[j][i]=-dizi[i];
                    }else{
                    dp[j][i]=fmin(dp[j+1][i+1]-dizi[i],dp[j+1][i]-dizi[i+il]);
                    }
                
                }else{
                if(j==n){
                    dp[j][i]=dizi[i];
                    }else{
                    dp[j][i]=fmax(dp[j+1][i+1]+dizi[i],dp[j+1][i]+dizi[i+il]);

                    }
                
                }
            }
        }
   /* for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
    cout<<dp[1][1];
    return 0;
}