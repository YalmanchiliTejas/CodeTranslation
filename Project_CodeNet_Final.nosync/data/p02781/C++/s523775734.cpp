//Dragon_warrior7(IITK)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pb push_back
#define nl cout << '\n'
#define sor(x) sort(x.begin(), x.end())
#define rev(v) reverse(v.begin(), v.end())
#define lb(v, temp) lower_bound(v.begin(), v.end(), temp)
#define ub(v, temp) upper_bound(v.begin(), v.end(), temp)
#define fi first
#define se second
#define llmax 1000000000000000000
#define deb(x) cout << #x << " " << x << "\n"
#define pll pair<ll, ll> 
#define vll vector<ll> 
#define rub cout << "\n------------------------------------\n"
typedef  tree < int ,  null_type ,  greater<int> ,  rb_tree_tag ,  tree_order_statistics_node_update > oset;
void read(vector<ll> &v)
{
	for (int i = 0; i < v.size(); i++)
		cin >> v[i];
}

void print(vector<ll> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}
ll n,m,a,b,c,t,temp,x,y;
string str;
ll fun(ll n,ll r)
{
    if(r==0)
    return 1;
    if(r==1)
    return n;
    return ((n)*(n-1))/2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	ll k;
	cin>>k;
	ll ans=0;
	const int value=pow(9,k);
	for(int i=k;i<=s.size();i++)
	{
	  if(i!=s.size())
	  {
	      ans+=value*fun(i-1,k-1);
	  }
	  if(i==s.size())
	  {
	      string str;
	      str.resize(s.size());
	      for(int x=0;x<str.size();x++)
	      str[x]='0';
	     for(int x=1;x<=9;x++)
	     {
	        str[0]=x+'0';
	        if(k==1)
	        {
	            if(str<=s)
	            ans++;
	        }
	        else if(k==2)
	        {
	            
	            for(int j=1;j<s.size();j++)
	            {
	                if(j!=1)
	                {
	                    str[j-1]='0';
	                }
	                for(int y=1;y<=9;y++)
	                {
	                    str[j]='0'+y;
	                    if(str<=s)
	                    ans++;
	                }
	            }
	        }
	        else
	        {
	            for(int j=1;j<s.size();j++)
	            {
	                if(j!=1)
	                {
	                    str[j-1]='0';
	                }
	                for(int y=1;y<=9;y++)
	                {
	                    str[j]='0'+y;
	                    for(int x=j+1;x<s.size();x++)
	                    {
	                      if(x!=j+1)
	                      {
	                         str[x-1]='0';
	                      }
	                      for(int val=1;val<=9;val++)
	                         {
	                             str[x]='0'+val;
	                             if(str<=s)
	                             ans++;
	                         }
	                    }
	                }
	            }
	        }
	     }
	  }
	}
	cout<<ans;
}