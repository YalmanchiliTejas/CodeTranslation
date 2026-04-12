/**
 *   created: 12 April 2019  00:37:24
**/
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int , int> pii;
typedef vector< pair<int , int> > vii;
typedef long long ll;
typedef vector<long long> vl;
typedef pair<long long , long long> pll;
typedef vector< pair<long long , long long> > vll;

#define PB push_back
#define PPB pop_back
#define all(c) (c).begin,(c).end()
#define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define INFLL 2000000000000000007
#define INF 2000000007
#define MOD 1000000007


#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif


void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

//                                        //AUTHOR: Kaushalesh Shukla

//=========================================================================================================
int main(){
	int tc=1;
	// cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		vi v(n);
		rep(i,0,n)
		cin>>v[i];
		int max=0,res=0;
		rep(i,0,n){
			if(max<=v[i]){
				res++;
				max = v[i];
			}
		}
		cout<<res<<endl;
	}
	return 0;
}