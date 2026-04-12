#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 998244353
#define pb push_back
#define ff first
#define ss second
#define con continue
#define ub upper_bound
#define lb lower_bound
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

const int dx8[] = {-1, 0, 1, 0,1,1,-1,-1};
const int dy8[] = {0, -1, 0, 1,1,-1,1,-1};


unordered_map<ll,ll> m1 ;
void solve()
{
    m1.clear();
 ll n,x,m ;
 cin >> n >> x >> m;
 vector<ll>arr1;
 vector<ll>arr2 ;
 arr1.pb(x);
 arr2.pb(x);
 m1[x]=0;
  for(ll i =1 ;i<n;i++)
 {
     arr1.pb(0);
     arr2.pb(0);
  arr1[i]=(arr1[i-1]*arr1[i-1])%m;
  arr2[i]=arr2[i-1]+arr1[i];
     if(m1.count(arr1[i])!=0)
     {
        // cout <<"hello" << endl;
         ll len= i-m1[arr1[i]];
         ll sum = arr2[i]-arr2[m1[arr1[i]]];
         ll rem= n-i;
         ll ans=0 ;
         ans= arr2[i-1]+ (rem/len)*sum;
         ll a = m1[arr1[i]] ;
         ll b = a+ (rem%len) -1 ;
        for (ll j=a ;j<=b;j++)
            ans+= arr1[j];
         cout << ans<< endl;

         return ;
     }
     m1[arr1[i]]=i;
 }


 cout << arr2[n-1]<< endl;

}



int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
   solve();
}
