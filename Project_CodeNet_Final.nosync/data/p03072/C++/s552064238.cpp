#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(n) for(int i=0;i<n;i+=1)
#define prarr(a,n) rep(n) cout<<a[i]<<endl printf("%s\n"," " );
#define sc(a) scanf("%d",&a);
#define scl(a) scanf("%lld",&a);
#define scf(a) ascanf("%f",&a);
#define ff first
#define ss second
#define pu push_back
#define inf 1000000001
#define MOD 1000000007 
#define INF 100000000000001
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int a[1000];
    cin>>n;
    rep(n) cin>>a[i];
    int ans = 0;
    stack<int> s;
    s.push(a[0]);
    for(int i = 1;i<n;)
    {
    	while(i<n && (s.empty()||s.top()>a[i]))
    	s.push(a[i++]);	
    	while(!s.empty() && s.top()<=a[i] )
    		s.pop();
    	if(s.empty()) ans++;
    }
    cout<<ans+1<<endl;
    return 0;

}
    