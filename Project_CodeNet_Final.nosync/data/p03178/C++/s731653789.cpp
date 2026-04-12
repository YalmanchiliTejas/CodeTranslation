#include<bits/stdc++.h>

using namespace std;


int dp[10000][100][2];
string s ;
int M =1e9+7;
int dd;
int k;
int mod(int x ,int y){
    
    return (dd+x%dd-y%dd)%dd;
}
int fun(int n , int d, int f){
    // cout<<n<<" "<<d<<" "<<f<<endl;
    if(n==k){
        if(d==0)return 1;
        return 0;
    }
    if(dp[n][d][f]!=-1)return dp[n][d][f];
     long long int ans =0;
    if(f==1){
        for(int i=0;i<10;i++){
            // cout<<d<<" "<<i<<" "<<(d-i)%dd<<endl;
            ans+=fun(n+1,mod(d,i),f);
        }
        ans%=M;
    }else{
        int x = s[n]-'0';
        ans+=fun(n+1,mod(d,x),0);
        for(int i =x-1;i>=0;i--){
            ans+=fun(n+1,mod(d,i),1);
        }
        ans%=M;
    }
    return dp[n][d][f]=ans;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>s;
    k = s.size();
    cin>>dd;
    memset(dp,-1,sizeof dp);
    cout<<(fun(0,dd,0)-1+M)%M<<endl;
    return 0;
}



