#include<bits/stdc++.h>
 using namespace std;
 
 // #define  int           long long
 #define pb                push_back
 #define ppb               pop_back
 #define pf                push_front
 #define ppf               pop_front
 #define all(x)            (x).begin(),(x).end()
 #define uniq(v)           (v).erase(unique(all(v)),(v).end())
 #define sz(x)             (int)((x).size())
 #define fr                first
 #define sc                second
 #define pint              pair<int,int>
 #define rep(i,a,b)        for(int i=a;i<b;i++)
 #define mem1(a)           memset(a,-1,sizeof(a))
 #define mem0(a)           memset(a,0,sizeof(a))
 #define ppc               __builtin_popcount
 #define ppcll             __builtin_popcountll
 #define vint			   vector<int>
 #define vpint			   vector<pair<int,int>>
 #define mp                make_pair


 void reader() 
 { 
 #ifndef ONLINE_JUDGE 
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout); 
 #endif
 }
 
 void fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}
 
 
 
 void solve()
 {
 
 int e=1e9+7;
 int n;
 cin>>n;
 long long int a[n],b[n];
 rep(i,0,n)
 {
 	cin>>a[i];	
 	b[i]=a[i];
 } 
 rep(i,1,n)
 b[i]+=b[i-1];

int sum=0;
 for(int i=0;i<n-1;i++)
 	sum=((sum%e)+(1LL*(a[i]%e)*((b[n-1]-b[i])%e))%e)%e;

if(n==1)
	cout<<a[0];
else
cout<<sum;
 
 
 }
 
 
 
 signed main()
 {
 	reader(); fastIO();
 	long long t=1;
 	//cin>>t;
 	while(t--) solve();
 	return 0;
 }