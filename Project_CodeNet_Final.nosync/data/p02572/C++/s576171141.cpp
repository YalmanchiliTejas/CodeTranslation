/*----------------------------------------------------*
* लेखक --> अमित सिंह
* संस्थान --> राष्ट्रीय प्रौद्योगिकी संस्थान, कुरुक्षेत्र
*-----------------------------------------------------*/
   #include <bits/stdc++.h>
   using namespace std;
   #define ll long long
   #define w(t) int t; cin>>t; while(t--)
   #define fo(i,n) for(int i=0;i<n;i++)
   #define endl "\n" 
   #define MOD 1000000007
   void Tez(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
   }
   int main(){
      Tez();
      int n;
      cin>>n;
      ll a[n];
      fo(i,n) cin>>a[i];
      ll ans=0;
      ll arr[n-1];
      ll sum=0;
      for(int i=0;i<n;i++) sum=(sum+a[i])%MOD;
      for(int i=0;i<n-1;i++){
         arr[i]=((sum-a[i])%MOD+MOD)%MOD;
         // arr[i]=sum-a[i];
         sum=arr[i];
      }
      for(int i=0;i<n-1;i++){
         ans=(ans+a[i]*arr[i])%MOD;
      }
      cout<<ans;
      return 0;
   }

