#include<bits/stdc++.h>
 
using namespace std;
 
#define ff              first
#define ss              second
#define ll             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void sb()
{	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
//int dp[3001][3001];
ll dp[3001][3001];
ll a[3005];
ll winner( int i,int j){
//int dp[n+1][n+1];
//memset(dp,-1,sizeof dp);
   if(i>j){
       return 0 ;
   }
   if(dp[i][j]!=-1){
     return dp[i][j];
   }
   if(i==j){
     return dp[i][j]=a[i]; 
   }
   
   dp[i][j]=max(a[i]-winner(i+1,j),a[j]-winner(i,j-1));     
 
 
   return dp[i][j];
 
  
 
}
 
//int winner(int a[],int n){
    //int dp[n+1][n+1];
    //memset(dp,0,sizeof dp);
    //dp[0]=0;
    //int X,Y;
    //dp[0][0]=0
    //for(int i=n;i>0;i--){
        //for(int j=i;j<n+1;j++){
            //if(i==0&&j==0){
                //dp[i][j]=0;
            //}
            //if(i==j){
                //dp[i][j]=a[i];
            //}
            //if(i>j){
               // dp[i][j]=0;
           // }
            //if(i<j){
              //  dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
           // }
        //}
   // }
//return dp[1][n];
    
    
//}
int main() {
ll n;
    cin>>n;
   //long long  int a[n];
   memset(dp,-1,sizeof(dp));
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<winner(0,n-1);
}