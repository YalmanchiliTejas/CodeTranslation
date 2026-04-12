#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define tr(c,it) for(auto it=c.begin();it!=c.end();it++)
#define fr(i,n) for(lli i=0;i<(n);i++)
#define inc(i,a,b) for(lli i=a;i<=b;i++)
#define dec(i,a,b) for(lli i=a;i>=b;i--)
#define fr2(i,n) for(int i=0;i<(n);i++)
#define inc2(i,a,b) for(int i=a;i<=b;i++)
#define dec2(i,a,b) for(int i=a;i>=b;i--)
#define ymin(a,b)  (a=min((a),(b)))
#define ymax(a,b)  (a=max((a),(b)))
#define sz(x) (lli)(x).size()
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr<< *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000007;
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))
lli dp[10010][2][2][101];
string L,R;
lli d;
lli getans(lli lev,lli tlo,lli thi,lli rem)
{
	if(lev>=R.length())
	{
		if(rem==0)
			return 1;
		else
			return 0;
	}
	if(dp[lev][tlo][thi][rem]!=-1)
		return dp[lev][tlo][thi][rem];
	lli blo=0;
	lli bhi=9;
	if(tlo)
		blo=L[lev]-'0';
	if(thi)
	{
		bhi=R[lev]-'0';
	}
	lli ans=0;
	for(lli i=blo;i<=bhi;i++)
	{
		lli ntlo=tlo;
		lli nthi=thi;
		if(i>L[lev]-'0')
			ntlo=0;
		if(i<R[lev]-'0')
			nthi=0;
		ans+=getans(lev+1,ntlo,nthi,(rem+i)%d);
		ans=ans%MOD;
	}
	return dp[lev][tlo][thi][rem]=ans;
}
void solve()
{
	L="1";
	cin>>R>>d;
	//reverse(all(R));
	
	reverse(all(L));

	//R=to_string(r);
	lli l1=L.length();
	lli l2=R.length();
	while(l1<l2)
	{
		L+='0';
		l1++;


	}

	reverse(all(L));
	//reverse(all(R));
	//cout<<L<<" "<<R<<endl;
	mset(dp,-1);
	//cout<<r.size()<<endl;
	lli p=getans(0,1,1,0);
	// for(lli i=0;i<2;i++)
	// {
	// 	for(lli j=0;j<2;j++)
	// 	{
	// 		for(lli k=0;k<2;k++)
	// 		{
	// 			for(lli ii=0;ii<d;ii++)
	// 			{
	// 				cout<<i<<" "<<j<<" "<<k<<" "<<ii<<" ";
	// 				cout<<dp[i][j][k][ii]<<endl;
	// 			}
	// 		}
	// 	}
	// }
	cout<<p<<endl;
}
int main()
{
	// 	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	IOS
	// clock_t start,end;
	// start=clock();
	// int t;
	// cin>>t;
	// for(int i=1;i<=t;i++)
	// {
	// 	cout<<"Case #"<<i<<": ";
	// 	solve();

	// }
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
	solve();
}
