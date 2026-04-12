#include<bits/stdc++.h>
using namespace std;

# define C continue;
# define R return

#define int long long
# define D double
# define I insert
# define ld long double
# define ull unsigned long long
# define ui unsigned int

# define pb push_back
# define pf push_front

# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
# define vd vector < D >
# define vull vector < ull >
# define vld vector < ld >

# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvs vector < vs >
# define vvd vector < vector < D > >
# define vvld vector < vector < ld > >

# define all(v) v.begin() , v.end()
# define allcomp(v) v.begin() , v.end() , comp

# define pii pair < int , int >
# define pll pair < ll , ll >
# define pld pair < ld , ld >
# define pDD pair < D , D >

# define vpld vector < pld >
# define vpii vector < pii >
# define vpDD vector < pDD >

# define vvpii vector < vector < pii > >
# define F first
# define S second
# define mp make_pair

#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type, vector<type>, greater<type>>

#define mii map<int, int>
#define mll map<ll, ll>
#define mci map<char, int>
#define msi map<string, int>
#define mis map<int, string>
#define mib map<int, bool>
#define mcb map<char,bool>

#define umii unordered_map<int, int>
#define umll unordered_map<ll, ll>
#define umci unordered_map<char, int>
#define umsi unordered_map<string, int>
#define umis unordered_map<int, string>

#define init(arr,val) memset(arr,val,sizeof(arr))
#define REP(i,a,b) for(int i=a; i<b; i++)
#define distance(a,b,p,q) sqrt((p-a)*(p-a) + (q-b)*(q-b))

# define pp(n) printf("%.10Lf",n);
# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);

string vow = "aeiou";
int month[] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int dxhorse[] = { -2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};

const int dx[] = { -1 , 0 , 1 , 0 } ;
const int dy[] = { 0 , 1 , 0 , -1 } ;

const ld pie = 3.1415926535897932384626 ;
const int mod = 1e9 + 7 ;
#define test int t; cin>>t;
# define fast ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);
/// Tip : If a and b are positive integers ; we may say - ceil (a/b) = 1 + floor ( (a-1)/b ) .
void a_b_c()
{
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
}

void solve()
{
   int n; cin>>n;
   if(n>=30) cout<<"Yes";
   else cout<<"No";
}
int32_t main()
{	fast
    int t=1;
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    //int t;  cin>>t;
    for(int i=1; i<=t; i++) solve();

}
