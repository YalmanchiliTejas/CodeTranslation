#include<bits/stdc++.h>
  #define f(i,a,b) for(int i=a;i<b;i++)
  #define ll long long
  #define vll vector<long long>
  #define mll map<ll,ll>
  #define pll pair<long long,long long>
  #define pb(x) push_back(x)
  #define F first
  #define S second
  #define print(v) for(auto it:v)cout<<it<<" "
  #define mod 1000000007   //10^9 +7
  #define sorty(v) sort(v.begin(),v.end())
  #define it(v) v.begin(),v.end()
using namespace std;  

int main() {
  string s;
  int flag=0;
  cin>>s;
  for(int i=1;i<3;i++){
    if(s[i]!=s[i-1])flag=1;
  }
  if(flag==1)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;



	return 0;
}