#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VV vector
#define pb push_back
#define bitc  __builtin_popcountl
#define m_p make_pair
#define inf 1000000000000000000ll
#define MAXN 1000001
#define eps 0.0000000001
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>//usage rand<long long>()
T rand() {
    return uniform_int_distribution<T>()(rng);
}

// string to integer stuuu()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

//////////////

#define S second
#define F first
#define int long long  
///////

long long modinverse(long long a, long long b)
{
    long long b0 = b, t, q;
    long long x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}

signed main()
{
	fastio;
	#ifdef ANIKET_GOYAL
		freopen("inputf.in","r",stdin);
		freopen("outputf.in","w",stdout);
	#endif
	int mo=1000000007;
	int n,k,m;
	cin>>n>>m>>k;
	int fac[200001];
	int ifac[200001];
	fac[0]=1;
	ifac[0]=modinverse(fac[0],mo);
	for(int i=1;i<200001;++i)
	{
		fac[i]=(fac[i-1]*i)%mo;
		ifac[i]=modinverse(fac[i],mo);
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			ans+=((m-j)*(((i*(i-1))/2)%mo))%mo;
			ans%=mo;
			ans+=(m*((((n-i)*(n-i+1))/2)%mo))%mo;
			ans%=mo;
			ans+=((n-i)*(((j*(j-1))/2)%mo))%mo;
			ans%=mo;
			ans+=(n*((((m-j)*(m-j+1))/2)%mo))%mo;
			ans%=mo;
			ans+=(i*((((j)*(j-1))/2)%mo))%mo;
			ans%=mo;
			ans+=(j*((((i)*(i-1))/2)%mo))%mo;
			ans%=mo;	
			// cout<<ans<<" ";
		}
	}
	ans*=modinverse(2,mo);
	ans%=mo;
	int nu=n*m-2;
	int de=k-2;
	// cout<<((fac[nu]*((ifac[nu-de]*ifac[de])%mo))%mo)<<"\n";
	cout<<(ans*((fac[nu]*((ifac[nu-de]*ifac[de])%mo))%mo))%mo;
}