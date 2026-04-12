#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1


#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
						 stringstream _ss(_s); \
						 istream_iterator<string> _it(_ss); \
						 err(_it, args); }
#else
#define error(args...)		42
#endif


void err(istream_iterator<string> it) { cerr << endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "; ";
	err(++it, args...);
}


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
#endif
}

int ceil2(int a, int b){
    int c = a / b;
    if (c * b < a) c++;
    return c;
}

const int MXDIG = 10002; 
int mem[MXDIG][2][105];

// string a;
// int d;


int digitdp(int pos, string &b, bool tight, int cur_sum, int d)
{
	if(pos == b.length())
		return cur_sum % d == 0;

	if(mem[pos][tight][cur_sum] != -1)
		return mem[pos][tight][cur_sum];


	int dig = b[pos] - '0';
	// error(pos, tight, cur_sum);

	int k = tight == 1 ? dig : 9;

	int ret = 0;

	for (int i = 0; i <= k; ++i)
	{
		bool newtight = (tight && i == dig);

		ret += digitdp(pos + 1, b, newtight, (cur_sum + i)%d, d);
		ret %= mod;
	}

	mem[pos][tight][(cur_sum)%d] = ret%mod;

	return ret%mod;
}

void init()
{
	for (int i = 0; i < MXDIG; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 105; ++k)
			{
				mem[i][j][k] = -1;
			}
		}
	}	
}

int32_t main()
{
	c_p_c();

	string a;

	int d;

	cin>>a>>d;

	init();

	digitdp(0, a, 1, 0, d);

	cout << (mem[0][1][0]-1 + mod) % mod;
	// cout << "\nend";


	return 0;
}