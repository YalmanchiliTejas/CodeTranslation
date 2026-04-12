#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T,typename... Args>
void err(istream_iterator<string>it,T a,Args... args)
{
	cerr<<*it<<"= " <<a<<" ";
	err(++it,args...);
}
void solve()
{
   int n; cin>>n;
   vector<int>h(n);
   rep(i,0,n-1) cin>>h[i];
   int res=0;
   vector<int>m(n);
   m[0]=h[0];
   if(n>1)
   {
   	rep(i,1,n-1)
   	m[i]=max(m[i-1],h[i]);
   }
   rep(i,0,n-1)
   {
   	if(m[i]==h[i])
   	res++;
   }
   cout<<res<<"\n";
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t=1;
  while(t--)
  {
	 solve();
  }
  return 0;
}


