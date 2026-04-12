#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vl vaector<long>
#define vll vector<long long int>
#define vC  vector<char>
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__)
ll pow(ll x, ll y,ll m) { ll res = 1;x=x%m; while (y > 0) { if (y & 1) res = ((res%m) * (x%m))%m; y = y >> 1; x = ((x%m) * (x%m))%m; } return res%m; }
template <typename Arg1> void ZZ(const char* name, Arg1&& arg1){std::cerr << name << " = " << arg1 << endl;}
template <typename Arg1, typename... Args>void ZZ(const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr(names + 1, ',');
	std::cerr.write(names, comma - names) << " = " << arg1;
	ZZ(comma, args...);
}
const ll INF = 0xFFFFFFFFFFFFFFFL;
clock_t time_p=clock();
void abhigyan10()
{time_p=clock()-time_p;cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";}
ll seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline ll rnd(ll l=0,ll r=INF){return uniform_int_distribution<ll>(l,r)(rng);}
#define clrbuf cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define preciset(x) cout<<setprecision(x)<<fixed;
const ll mod =1000000007;
int main()
{
   
        FastIO

        string c;
        cin>>c;

        if(c[0]==c[1]&& c[1]==c[2])
        	cout<<"No";
        else
        	cout<<"Yes";
        return 0;
    }
        	
