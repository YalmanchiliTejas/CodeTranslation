#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ctime>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define N 101
#define mod 1000000007
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<n;i++)
#define in(i,arr) for(auto &i:arr)cin>>i;
#define all(x) (x).begin(), (x).end()   // sort(all(v)) instead sort(v.begin(),v.end())
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define vi vector<int>
#define vl vector<int>
#define pb push_back
#define eb empalce_back
int pow(int base,int to)
{   int ans=1;
    while(to>0) {
        if (to & 1)
            ans *= base, to--;
        else base *= base, to /= 2;
    }
    return ans;

}
int main()
{ fast;
//  string s,t;
//  cin>>s>>t;
//  int count=0;
//  int ma=0;
//  int temp;
//  for(int i=0;i<t.size();i++)
//  {   temp=i;
//      for(int j=i;j<s.size()-(t.size()-i);j++)
//      {
//          if(s[j]==t[i])
//              i++,count++,ma=max(ma,count);
//          else {i=temp;count=0;}
//      }
//      i=temp+1;
//  }
////for(int k=0;k<s.size();k++){
////for (int i=k,j=0;i<s.size(),j<t.size();i++)
////{
////    if(s[i]==t[j])
////        j++,count++;
////    else ma=max(ma,count),j++,count=0;
////
////}}
//  cout<<t.size()-ma;
  int n;
  cin>>n;
  ll arr[n];
  in(i,arr);ll ans=0;
  ll arr1[n];
  arr1[n-1]=arr[n-1];
 for(int i=n-2;i>=0;i--)
 {
     arr1[i]=(arr1[i+1]%mod+arr[i]%mod)%mod;
 }
 for(int i=0;i<n-1;i++)
 {
     ans=(ans%mod+((arr[i]%mod)*(arr1[i+1]%mod))%mod)%mod;
 }
 cout<<ans;



}

