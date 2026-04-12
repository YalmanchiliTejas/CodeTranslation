				#include <bits/stdc++.h>
				using namespace std;
				#define ll long long
				#define mod 1000000007
				#define pll pair<long,long>
				#define se second
				#define fi first
				#define pb push_back
				#include <ext/pb_ds/assoc_container.hpp>
				#include <ext/pb_ds/tree_policy.hpp>
				using namespace __gnu_pbds;

				typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
				typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update>pllordered_set;
				
				const ll m=998244353;
				ll cache[3002][3002];
				ll n,s;
				vector<ll> v;
				ll dp(ll idx,ll s)
				{
					//cout<<idx<<" "<<s<<" "<<cache[idx][s]<<endl;
					if(s==0)
						return n-idx+1;
					
					if(s<0 || idx>=n)
						return 0;
					
					if(cache[idx][s]!=-1)
						return cache[idx][s];
					ll ans=0;
					ans=dp(idx+1,s)+dp(idx+1,s-v[idx]);
					ans%=m;
					return cache[idx][s]=ans;
						
				}
				
				int main()
				{
					ios_base::sync_with_stdio(false);
					cin.tie(NULL);
					cin>>n>>s;	
					v.resize(n);
				
					for(ll i=0;i<n;i++)
						cin>>v[i];
					ll res=0;
					for(ll i=0;i<=3000;i++)
					{
						for(ll j=0;j<=3000;j++)
							cache[i][j]=-1;
					}
					for(ll i=0;i<n;i++)
						{res+=dp(i,s);res%=m;
						//	cout<<dp(i,s)<<endl;
						}
					res%=mod;
					cout<<res;
				}
				
