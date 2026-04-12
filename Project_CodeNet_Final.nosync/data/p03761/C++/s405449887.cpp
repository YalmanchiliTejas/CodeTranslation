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
int check(ll a, ll b) {

	ll a1 = 0, b1 = 0;
	while (a) {
		a1++;
		a /= 10;
	}
	while (b) {
		b1++;
		b /= 10;
	}


	return max(a1, b1);


}
string common(string s, string s1) {
	sort(all(s));
	sort(all(s1));
	string str = "";

	int i = 0, j = 0;
	while (i < s.size() and j < s1.size()) {
		// watch2(s[i],s1[j]);
		if (s[i] == s1[j]) {
			str += s[i];
			i++; j++;
		}
		else if (s[i] < s1[j])
			i++;
		else
			j++;
	}
	return str;
}

int main() {
	int i, m, k;
	long long int sum = 0;
	c_p_c();
	ll n;


	cin >> n;
	string a[n];
	fo(i, n) cin >> a[i];

	int ferq[27] = {0};

	// for (int i = 0; i < n; ++i)
	// {
	// 	for(char ch : a[i]){
	// 		ferq[ch-'a']++;
	// 	}
	// }

	// parray(ferq,27);
	// cout<<common(a[0],a[1]);
	if (n == 1) {
		sort(all(a[0]));
		cout<<a[0]<<endl;

		return 0;
	}

	string str = a[0];
	for (int i = 1; i < n; ++i)
	{
		/* code */
		str = common(str, a[i]);
	}
	cout << str << endl;

}