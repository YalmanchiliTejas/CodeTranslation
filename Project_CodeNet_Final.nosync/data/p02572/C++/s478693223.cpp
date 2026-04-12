/**********************************************************************************************
******************************AUTHOR:**********************************************************
****************************ASHISH RANJAN******************************************************
***********************************************************************************************/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<chrono>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
using namespace std::chrono;
/*
auto start = high_resolution_clock::now();
auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
*/
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define mod 1000000007
#define fr(i,n) for(int i=0;i<(int)n;i++)
#define frs(i,a,b) for(int i = a;i<b;i++)
#define meme(a,b,c) memset(a,b,sizeof(c)); //works only for 0 and -1
int main(){
  fast();
  int n;
  cin>>n;
  vector<ll> v(n);
  fr(i,n)cin>>v[i];
  vector<ll> prefix(n+1,0);
  for(int i=n-1;i>=0;i--){
  prefix[i] = prefix[i+1] + v[i];
  }
  ll ans = 0;
  fr(i,n){ans += (v[i]*(prefix[i+1]%mod))%mod;ans %=mod;}
  cout<<ans;
 return 0;
  
}


