#include <bits/stdc++.h>
#include<deque>
#define jio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
//#define mp make_pair
#define pb push_back
#define lld long long int
#define clr clear()
#define ff first
#define ss second
#define N 1000005
//#define M 1000
#define endl '\n'
#define c_s_b() __builtin_popcount()

#define sze 10000009
#define pii pair<int,int>
#define big 3050
#define int long long

using namespace std;
const ll INF = 1e18L+5;
int n,k;
int a[big];
int dp[big][big][2];


//bool x
int fun(int s,int e,int turn){
    //turn =1 taro
    //turn=0 ziro

   if(s>e){
      return 0;
   }
  /* if(s==e){
    return a[s];
   }  */
   if(dp[s][e][turn]!=-1) return dp[s][e][turn];
   int ans=0;
   if(turn==1){
      ans=max(fun(s+1,e,1-turn)+a[s],fun(s,e-1,1-turn)+a[e]);
   }
   if(turn==0){
      ans=min(fun(s+1,e,1-turn)-a[s],fun(s,e-1,1-turn)-a[e]);

   }
   return dp[s][e][turn]=ans;







}



int32_t main(){
   jio;
    cin>>n;
    //int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
       // sum+=a[i];
    }
     for(int i=0;i<big;i++){
        for(int j=0;j<big;j++){
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
     }
   // memset(dp,-1,sizeof(dp));
   //cout<<"sum "<<sum<<endl;
   int x=fun(0,n-1,1);//1 for taro // 0 for jiro
   /*int y=sum-x;
   cout<<x<<" "<<y<<endl;
   cout<<abs(x-y)<<endl;*/
   cout<<x<<endl;




    return 0;


}
