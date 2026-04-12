#include<bits/stdc++.h>
#define int long long
#define rep(i,m,n) for(int i=m;i<n;i++)
#define repr(i,n,m) for(int i=n;i>=m ;i--)
#define MOD 1000000007
#define float long double
#define pb push_back
#define mp make_pair
#define pp pop_back
#define pi 3.141592653589793238
#define print(v) for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
using namespace std;
bool sortbysec(const pair<int,int> &a,
             const pair<int,int> &b)
{
   return (a.second < b.second);
}
int lcm(int a, int b)  
 {  
    return (a*b)/__gcd(a, b);  
 }  
bool sortinrev(const pair<int,int> &a,  
              const pair<int,int> &b)
{
      return (a.first > b.first);
}
void solve()
{
	int n;
	cin>>n;
	if(n>=30)
		cout<<"Yes";
	else
		cout<<"No";
}    
signed main()
{
                     // #ifndef ONLINE_JUDGE
                     // freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
                     // #endif 
  int t=1;
 //cin>>t;
  while(t--){
  solve();
  cout<<"\n";
}
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
 return 0;
}  
