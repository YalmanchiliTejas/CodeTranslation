#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define MAX 1000005
#define mod 1000000007
#define sp fixed<<setprecision(12)
using namespace std;
/*
vector<int> primes;
int sumprime[MAX];
bool is_prime[MAX];
void sieve(){
    is_prime[0]=is_prime[1]=true;
    for(int i=4;i<MAX;i+=2){
        is_prime[i]=true;
    }
    for(int i=3;i*i<MAX;i+=2){
        if(!is_prime[i]){
            for(int j=i*i;j<MAX;j+=i){
                is_prime[j]=true;
            }
        }
    }
    for(int i=1;i<MAX;i++){
        if(!is_prime[i]){
            sumprime[i]=sumprime[i-1]+i;
        }else{
            sumprime[i]=sumprime[i-1];
        }
    }
}
*/
/*
void lcs(char s1[],char s2[]){
    int n=strlen(s1);
    int m=strlen(s2);
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int sum=0;
            if(s1[i-1]==s2[j-1]){
                sum=1+dp[i-1][j-1];
            }
            else{
                sum=max(dp[i-1][j],dp[i][j-1]);
            }
            dp[i][j]=sum;
        }
    }
    
    int index=dp[n][m];
    //cout<<index<<endl;
    char ans[index+1];
    ans[index]='\0';
    index--;
    int x=n;
    int y=m;
    while(x>0 and y>0){
        if(dp[x-1][y]==dp[x][y-1] and dp[x-1][y]!=dp[x][y]){
            ans[index]=s1[x-1];
            index--;
            x--;
            y--;
        }else if(dp[x-1][y]>dp[x][y-1]){
            x--;
        }else{
            y--;
        }

    }
    //reverse(ans.begin(),ans.end());

    cout<<ans;
    return;
}
*/

int dp[3001][3001][2];

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    //double    pi=3.14159265358979323846;
    //sieve();
    int t=1;
    //sieve();
   // cin>>t;
    
    for(int tc=1;tc<=t;tc++){
        int n,sum=0;
        cin>>n;
        vector<int> v(n);
        for(int& x:v){
            cin>>x;
            sum+=x;
        }
        for(int i=0;i<n;i++){
            dp[i][i][0]=v[i];
            dp[i][i][1]=0;
        }
        for(int r_l=1;r_l<n;r_l++){
            for(int l=0;l+r_l<n;l++){
                int r=l+r_l;
                dp[l][r][0]=max(v[l]+dp[l+1][r][1],v[r]+dp[l][r-1][1]);
                dp[l][r][1]=min(dp[l+1][r][0],dp[l][r-1][0]);
            }
        }
        int x=dp[0][n-1][0];
        int ans=(2*x)-sum;
        cout<<ans<<'\n';

    }
    
    return 0;
    
}