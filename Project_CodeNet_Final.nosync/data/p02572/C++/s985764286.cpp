#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cinttypes>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<stack>


#define FSCNd64 "%" SCNd64
#define FPRId64 "%" PRId64

using namespace std;

using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vpii=vector<pii>;

#define PI 3.1415926535897932384626433832795

template<typename X>
bool max_u(X&m, X v)
{
	if(m<v)
	{
		m=v;
		return true;
	}
	return false;
}


template<typename X>
bool min_u(X&m, X v)
{
	if(m>v)
	{
		m=v;
		return true;
	}
	return false;
}


using ll=long long;

class mod_ll
{
public:
	ll m_v;
	static const ll m_m=1000000007; // prime value ex. 1000000009
	mod_ll(ll v=0) : m_v(v%m_m) {}
	mod_ll& operator = (ll rhs)
	{
		m_v=rhs%m_m;
		return *this;
	}
	ll operator ()(){return (m_v+m_m)%m_m;}
	mod_ll& operator += (const mod_ll rhs)
	{
		m_v=(m_v+rhs.m_v)%m_m;
		return *this;
	}
	const mod_ll operator + (const mod_ll rhs)
	{
		auto ret=*this;
		return ret+=rhs;
	}
	mod_ll& operator -= (const mod_ll rhs)
	{
		m_v=(m_v-rhs.m_v+m_m)%m_m;
		return *this;
	}
	const mod_ll operator - (const mod_ll rhs)
	{
		auto ret=*this;
		return ret-=rhs;
	}
	mod_ll& operator *= (const mod_ll rhs)
	{
		m_v=(m_v*rhs.m_v)%m_m;
		return *this;
	}
	const mod_ll operator * (const mod_ll rhs)
	{
		mod_ll ret=*this;
		return ret*=rhs;
	}
	const mod_ll operator ^ (ll rhs)
	{
		mod_ll t=*this;
		mod_ll ret(1LL);

		for(;rhs>0;rhs>>=1)
		{
			if(rhs&1) ret*=t;
			t*=t;
		}
		return ret;
	}
	mod_ll& operator /= (mod_ll rhs)
	{
		mod_ll t=rhs^(m_m-2);
		return *this*=t;
	}
	const mod_ll operator / (const mod_ll rhs)
	{
		mod_ll ret=*this;
		return ret/=rhs;
	}
};


mod_ll mod_fact(int n)
{
	static vector<mod_ll> memo(1);

	if((int)memo.size()<=n)
	{
		if(memo.size()==1)
		{
			memo[0]=1;
		}
		for(int i=memo.size();i<=n;i++)
		{
			memo.push_back(memo.back()*i);
		}
	}
	return memo[n];
}


mod_ll mod_nCr(int n, int r)
{
	if(n<=0) return 1;
	return mod_fact(n)/(mod_fact(n-r)*mod_fact(r));
}


mod_ll mod_nCr2(int n, int r)
{
	mod_ll bunsi(1);
	mod_ll bunbo(1);
	if(r*2>n) r=n-r;

	for(int i=0;i<r;i++)
	{
		bunsi*=(n-i);
		bunbo*=(i+1);
	}
	return bunsi/bunbo;
}


mod_ll mod_nPr(int n, int r)
{
	return mod_fact(n)/mod_fact(n-r);
}


struct solve
{
	solve(){}
	ll operator()() {
		return 0;
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(;;)
	{
		int n;
		cin >> n;
		if(cin.fail()) break;

		vll a(n);
		for(auto&m:a) cin >> m;

		mod_ll w(0), s(0);
		for(auto m:a)
		{
			w+=m;
			s+=m*m;
		}

		mod_ll ans=w*w;
		ans-=s;
		ans/=2;

		cout << ans() << "\n";
	}
	return 0;
}
