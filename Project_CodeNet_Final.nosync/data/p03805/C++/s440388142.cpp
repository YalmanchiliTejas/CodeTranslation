#include<bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
# define M_PI    3.14159265358979323846
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define w(x)  int x; cin>>x; while(x--)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define watch3(x,y,z) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<" and "<<(#z)<<" is "<<(z)<<"\n"
#define watch4(x,y,z,q) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<" and "<<(#z)<<" is "<<(z)<<" and "<<(#q)<<" is "<<(q)<<"\n"
#define MOD 1000000007
#define INF 1000000007;
#define F first
#define S second
#define pb(x) push_back(x);


#define ll  long long
#define all(c) (c).begin(),(c).end()
#define endl "\n"

typedef vector<int> vl;
typedef vector< vl > vvl;
typedef pair< int, int> pll;
typedef map< int, int> mll;


#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif





void c_p_c()
{
#ifndef ONLINE_JUDGE
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void parray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
int no = 1, n1;
int recu(int n, int k, int val) {


	if (n == n1) {
		return min(val * 2, val + k);
	}
	return min( recu(n + 1, k, 2 * val), recu(n + 1, k, val + k)              );


}
int digit(int n) {

	int temp = 0;
	while (n) {
		// temp += n % 10;
		n = n / 10;
		temp++;
	}



	return temp;
}

bool check(int a[], int n) {
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if (a[i] % 2)
			return false;
	}
	return true;
}
bool ispalin(int n) {


	string  str = to_string(n);
	// cout<<str<<endl;


	for (int i = 0; i < str.size() / 2; ++i)
	{
		/* code */
		// watch2(str[i],str[str.size()-i-1]);
		if (str[i] != str[str.size() - i - 1]) {
			return false;
		}
	}


	return true;


}

bool is_palindrome(string s) {
	int n = s.size();


	for (int i = 0; i < n / 2; ++i)
	{
		/* code */
		if (s[i] != s[n - i - 1])
			return false;
	}
	return true;
}
int check(string s, string t) {
	int sum = 0;


	for (int i = 0; i < s.size(); ++i)
	{
		/* code */
		if (s[i] == t[i])
			sum++;
	}


	return sum;



}

// int ad[10];
vector<int> ad[10];


int n;
int ans = 0;

void dfs(int node , int parent, bool visited[]) {
	// watch()


	visited[node] = true;
	// cout << "-->" << node;
	for (int child : ad[node]) {
		// watch(child);
		if (!visited[child]) {


			dfs(child, node, visited);
			visited[child] = false;
		}

	}

	// watch2(parent, node);
	int kk=0;
	for (int i = 1; i <=n; ++i)
	{
		/* code */
		if(visited[i])
			kk++;
	}
	if(kk==n)
		ans++;

	// watch(ans);
	// return 0;


}

int main() {
	int i,  m, k;
	long long int sum = 1;
	c_p_c();
	// cin>>n;
	int a, b;
	cin >> n >> m;
	bool visited[10] = {false};

	// watch2(n, m);
	for (int i = 0; i < m; ++i)
	{
		/* code */
		cin >> a >> b;
		// watch2(a,b);
		ad[a].pb(b);
		ad[b].pb(a);
	}

	 dfs(1, -1, visited);
	cout << ans << endl;

	// for (int i = 1; i <=n; ++i)
	// {
	// 	 code
	// 	cout<<visited[i]<<endl;
	// }


	return 0;

}
