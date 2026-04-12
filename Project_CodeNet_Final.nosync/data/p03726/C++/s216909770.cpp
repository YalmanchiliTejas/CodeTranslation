#include<bits/stdc++.h>
using namespace std;

#define pi 3.141592654
#define fix(n) cout << fixed << setprecision(n)

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ren(i,a,b) for(int i=a;i>=b;i--)

#define si(d)  scanf("%d",&d)
#define sll(d) scanf("%lld",&d)
#define pin(d) printf("%d\n",d)
#define pln(d) printf("%lld\n",d)
#define nl 	   printf("\n")

#define ll long long
#define ull unsigned long long

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define chalne_de continue
int mod=1000000007;
const int N = 100005;

ll gcd(ll a , ll b)
{
    if ( b == 0)
    return a;
    return gcd( b, a % b);
}
vector<int> v[N];
bool visited[N];
bool leaf(int parent, int elem)
{
	int l = v[elem].size();
	for ( int i = 0 ; i < l ; i++)
	{
		int child = v[elem][i];
		if ( child == parent)continue;
		bool find_ = leaf(elem,child);
		if ( find_)
		{
			if ( visited[elem]){
				visited[elem] = false;
				return false;
			}
			else
			{
				visited[elem] = true ;
			}
		}
	}
	if ( !visited[elem])
	{
		visited[elem] = true;
		return true;
		}
	

	else
		return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n ;
	rep(i,0,n-1)
	{
		int x,y;
		cin >> x >> y ;
		v[x].pb(y);
		v[y].pb(x);
	}
	/*//bool visited[N];
	memset(visited,false,sizeof(visited));
	for ( int i = 1 ; i <= n ; i++)
	{
		int cnt = 0;
		//if ( visited[i] == false)
		int l = v[i].size();
		//cout << l <<endl;
		for ( int j = 0 ; j < l;j++)
		{
			int x = v[i][j];
			//visited[x] = true;
			//cout << x << " ";
			if ( v[x].size() == 1)
				cnt++;
		}
		//cout << endl;
		if ( cnt >= 2)
		{
			cout << "First";
			return 0;
		}
	}
	*/if ( n % 2 == 1)
	{
		cout << "First";
		return 0;
	}
	leaf(-1,1);
	bool first = false;
	for ( int i = 1 ; i <= n ; i++)
	{
		if ( visited[i] == false)
		{
			first = true ;
			break;
		}
	}
	if ( first )
		cout << "First";
	else
		cout << "Second";
	return 0;
}
