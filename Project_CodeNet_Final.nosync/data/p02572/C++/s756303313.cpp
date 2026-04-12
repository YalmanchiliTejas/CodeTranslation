				#include<bits/stdc++.h>
				using namespace std; 
				#define max(a, b) (a < b ? b : a) 
				#define min(a, b) ((a > b) ? b : a) 
				#define mo 1e9 + 7 
				#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
				#define FORL(a, b, c) for (int(a) = (b); (a) < (c); (a)++) 
				#define FORR(a, b, c) for (int(a) = (b); (a) > (c); (a)--) 
				#define INF 1000000000000000003 
				typedef long long int ll; 
				typedef vector<int> vi; 
				typedef vector<long long int> vl; 
				typedef pair<int, int> pi; 
				typedef pair<long long int, long long int> pl; 
				#define F first 
				#define S second 
				#define pb push_back 
				#define POB pop_back 
				#define mp make_pair 
				//const int M=mod;
				const int M=1e9+7;
				    long long mod(long long x){
					return ((x%M + M)%M);
				    }
				     long long add(long long a, long long b){
					return mod(mod(a)+mod(b));
				    }
								    long long mul(long long a, long long b){
					return mod(mod(a)*mod(b));
				    }
								int main()
				 {ios_base::sync_with_stdio(false);
				    cin.tie(NULL);
					int n;
					int m=1000000007;
					cin>>n;
					int  x;
					vi a,b;
					FOR(i,n)
					{cin>>x;
					a.pb(x);
					b.pb(x);
					}
					for(int i=1;i<n;i++)
					a[i]=add(a[i],a[i-1]);
					ll s=0;
					x=a[n-1];
					FOR(i,n)
					s=add(s,mul(b[i],(x-a[i])));
					cout<<s;
				return 0;
				}
					
		