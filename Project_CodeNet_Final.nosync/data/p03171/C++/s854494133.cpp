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

const int sz = 3005;
int mem[sz][sz];
int psum[sz];

int a[sz];

int n;

int solve(int i, int j)
{
	
	if(mem[i][j] != -1)
		return mem[i][j];

	if(i == j)
	{
		mem[i][j] = a[i];
	}
	else
	{
		int temp = a[i] + (i+1 < n ? ((psum[j] - psum[i+1] + a[i+1]) - solve(i+1, j)) : 0);
		int temp2 = a[j] + (j-1 >= 0 ? ((psum[j-1] - psum[i] + a[i]) - solve(i, j-1)) : 0);
		mem[i][j] = max(temp, temp2);
	}

	error(i,j, mem[i][j]);

	return mem[i][j];
}


int32_t main()
{
	c_p_c();

	cin>>n;

	for (int i = 0; i < sz; ++i)
	{
		for (int j = 0; j < sz; ++j)
		{
			mem[i][j] = -1;
		}
	}

	

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];

		if(i==0)
			psum[i] = a[i];
		else
			psum[i] = psum[i-1] + a[i];
	}

	solve(0,n-1);

	cout << 2*mem[0][n-1] - psum[n-1];

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << psum[i] << " " ;
	// }

	// cout << "\n";

	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout << mem[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	
	return 0;
}