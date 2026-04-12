/*input
9
*/
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())     
#define rep(i,j,n) for(ll i=j;i<n;i++)
#define mp make_pair
#define N 998244353
#define PI acos(-1.0)
//if (s.find('R') != std::string::npos)
//s.replace(s.find("10"), sizeof("10") - 1, "");
using namespace std;
bool comp(pair<string,ll>a,pair<string,ll>b){
  if(a.first==b.first) return a.second>b.second;
  return a.first<b.first;
}
int main()
{
  // added the two lines below 
  ios_base::sync_with_stdio (false); 
  cin.tie(NULL);
  cout.tie(0);
  
  ll n;
  cin>>n;
  ll arr[n];
  rep(i,0,n) cin>>arr[i];
  ll c=1,mx=arr[0];
  for(int i=1;i<n;i++){
    if(mx<=arr[i]) {
      c++;
      mx=arr[i];
    }
  }
  cout<<c;


}