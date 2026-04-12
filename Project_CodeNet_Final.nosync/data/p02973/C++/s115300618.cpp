#include"bits/stdc++.h"

using namespace std; 

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long LL;
typedef priority_queue<int> PQ_DESC;
typedef priority_queue<int, vector<int>, greater<int>> PQ_ASC;
typedef priority_queue<PII> PQ_DESC_PII;
typedef priority_queue<PII, vector<PII>, greater<PII>> PQ_ASC_PII;

#define SORT_ASC(c) sort((c).begin(), (c).end())
#define SORT_DESC(c) sort((c).begin(), (c).end(), greater<typeof((c).begin())>())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,n)
#define PER(i,n)  ROF(i,0,n)
#define SIZE(a) int((a).size())

#define ALL(a)  (a).begin(),(a).end()

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INT_LARGE = 1000000100;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

void Main()
{
	int n;
	cin >>n;
	VI a(n);
	REP(i, n) cin >> a[i];
	
	VI lis(n,-1);

	REP(i,n){
		*(lower_bound(ALL(lis), a[i]) -1) = a[i];
	}

	PER(i,n){
		if(lis[i] == -1){
			cout << n-i-1 << endl;
			return;
		}
	}

	cout << n << endl;
	

	return;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
    return 0;
}