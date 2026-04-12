



//   @author - Archit


#include<bits/stdc++.h>
using namespace std;


#define pb push_back
#define mp make_pair
#define ll long long
#define pll pair<ll,ll> 
#define all(v) v.begin(),v.end()
#define vll vector<ll> 
#define vvll vector<vll >
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second 
#define rjust(x) cout << std::right << std::setw(5) << x<<;
#define precise(x,y) cout<<std::fixed << std::setprecision(y) << x;
#define INF 1000000000000000

//INPUT
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void cres(vector<T>&Arr,int n)
{
	Arr.clear();
	Arr.resize(n);
}


template<typename T>
void cres(vector<vector<T> >&Arr,int row ,int col)
{
	Arr.clear();
	Arr.resize(row,vector<T>(col));
}

template<typename T>
void read(int x , vector<T>&Arr)
{
	for(ll i=x ;i<Arr.size();++i)
		cin>>Arr[i];
}

template<typename T >
void read(int x , vector<vector<T> >&Arr)
{
	for(ll i=x ;i<Arr.size();++i)
		{
			for(ll j=x ;j<Arr[i].size();++j)
				cin>>Arr[i][j];
		}
}

template<typename T >
void readg(vector<vector<T> >&Arr , int e)
{
	for(ll i=1 ;i<=e;++i)
		{
			ll x,y;
			cin>>x>>y;
			Arr[x].pb(y);
			Arr[y].pb(x);

		}
}

template<typename T>
void read(int x , T Arr[], int n)
{
	for(ll i=x ;i<n;++i)
		cin>>Arr[i];
}



//OUTPUT
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<typename T>
void write(int x , vector<T>&Arr)
{
	for(ll i=x ;i<Arr.size();++i)
		cout<<Arr[i]<<" ";
}

template<typename T>
void write(int x , vector<vector<T> >&Arr)
{
		for(ll i=x ;i<Arr.size();++i)
		{
			for(ll j=x ;j<Arr[i].size();++j)
				cout<<Arr[i][j]<< " ";
			cout<<"\n";
		}
}

template<typename T>
void write(int x , T Arr[], int n)
{
	for(ll i=x ;i<n;++i)
		cout<<Arr[i]<<" ";
}

template<typename T>
void write(set<T>&s)
{
	for(auto i : s) 
		cout<< i << " ";
}


template<typename T0, typename T1>
void write(map<T0,T1>&m)
{
	for(auto i : m) 
		cout<< i.ff << " " << i.ss<<"\n";
}



//FUNCTIONS
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// const int sieve_size = 100005;
// int sieve[sieve_size];

// void Sieve()
// {
// 	sieve[0] = sieve[1] = -1;
	
// 	for(int i=2 ;i<sieve_size ;i++)
// 		sieve[i]=i;

// 	for(int i = 2 ;i*i<=sieve_size ;++i)
// 	{
// 		if(sieve[i]==i)
// 		{
// 			for(int j = i*i ; j<sieve_size;j+=i)
// 			{
// 				if(sieve[j]==j)
// 				sieve[j]=i;
// 			}
// 		}
// 	}
// }
string k;
ll d;
const ll maxn = 1e5+10 , mod = 1e9+7;
ll dp[maxn][105][2];

ll rec(ll idx , ll sum , ll bada)
{

	//cout<<idx<<" "<<sum<<" "<<bada<<" "<<"\n";
	ll ans = 0 ;
	
	if(idx == k.size())
		return (sum%d == 0);

	if(dp[idx][sum][bada] != -1)
		return dp[idx][sum][bada]%mod;

	if(bada)
	{
		for(ll i = 0 ; i<=9 ;i++)
			ans = (ans%mod + rec(idx+1 , (sum + i)%d , bada)%mod)%mod;
	}
	else
	{
		for(ll i = 0 ; i<k[idx] - '0' ; i++)
			ans = (ans%mod + rec(idx+1,(sum+i)%d,1)%mod)%mod;
		ans = (ans%mod +rec(idx+1,(sum+ k[idx] - '0')%d ,0)%mod)%mod;
	}

	return dp[idx][sum][bada] = ans%mod;
}


int main()
{
	fast;

	memset(dp,-1,sizeof dp);
	cin>>k>>d;
	cout<<(rec(0,0,0)-1+mod)%mod;
















	return 0;
	
}


