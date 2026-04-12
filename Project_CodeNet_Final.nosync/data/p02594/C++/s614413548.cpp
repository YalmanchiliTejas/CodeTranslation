#include<bits/stdc++.h>
using namespace std;
typedef 	long long 							ll;
#define		mod									1000000007
#define 	ppi 								pair<ll,ll>
#define 	all(v) 								v.begin(),v.end()
#define 	prq									priority_queue
#define 	vi 									vector<ll>
#define     vip									vector<ppi>
#define 	forn(i,a,b)  						for(i=a;i<b;i++)
#define 	ford(i,a,b)   						for(i=a;i>b;i--)
#define 	endl 								"\n";
#define 	p_b 								push_back
#define 	m_p 								make_pair
#define     umap								unordered_map<ll,ll>
#define     uset                                unordered_set<ll>
#define     Stack								stack<ll>
#define     Queue								queue<ll>
#define     F									first
#define     S 									second				
void print1D(vector<ll> &v)
{
	cout<<"Debug Array:  ";
	for(ll i=0;i<v.size();i++)
 	   cout<<v[i]<<" ";
	cout<<"-----------------------------\n"; 
}

void print2D(vector<vector<ll>> &v)
{
	cout<<"Debug2d: ";
	ll n = v.size(),m=v[0].size();
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"--------------------------------------\n";
}

void printS(string &s)
{
	ll l=s.length(),i;
	cout<<"String: ";
	for(i=0;i<l;i++)
	{
		cout<<s[i];
	}
	cout<<"\n---------------------------------------\n";
}

void vectorInput(vector<ll> &v)
{
	ll n=v.size();
	for(ll i=0;i<n;i++){
	   cin>>v[i];
   }
}

void pairInput(vector<ll> &vp)
{
	ll n = vp.size(),i,j,k;
	for(i=0;i<n;i++)
	{
		cin>>vp[i];
	}
}

void swap(ll &a,ll &b)
{
	ll t=a;
	a=b;
	b=t;
}

void sol()
{
	
	ll i,j,k,n,m;
	cin>>n;
	if(n>=30)
	   cout<<"Yes\n";
	else
		cout<<"No";   		 
//	vi v(n);
	//vectorInput(v);
}

/*<----------------------------------------------------------------------------------------------------------------------------------------------->*/

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
	ll test=1;
//	cin>>test;
	while(test--)
	{
		sol();
		
	}
}