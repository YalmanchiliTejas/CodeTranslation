#include <bits/stdc++.h>

using namespace std;

#define db(x) cout << (x) << '\n';
#define all(x) x.begin(),x.end()
#define UNIQUE(x) sort(all(x)),x.resize(unique(all(x))-x.begin())
#define LB(v,x) lower_bound(all(v),x)
#define UB(v,x) upper_bound(all(v),x)
#define endl "\n"
#define F first
#define S second
#define PB push_back
#define int long long
#define trick int m = (l+r)>>1,lc=n<<1,rc=lc|1

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

int dy[]={0,1,1,1,0,-1,-1,-1};
int dx[]={-1,-1,0,1,1,1,0,-1};
const int maxn = 1e5;
const int OO = 1e18;
const int mod = 1e9 + 7;
const double PI = acos(-1);

void maxself(int &a,int b)
{a=max(a,b);}
void minself(int &a,int b)
{a=min(a,b);}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

//	freopen("name.in","r",stdin);
//	freopen("name.out","w",stdout);
	string s;
	cin >> s;
	int b=0,a=0;
	for(int i=0;i<s.size();i++)
	if(s[i]=='A')
	a++;
	else
	b++;
	if(a and b)
	cout << "Yes";
	else
	cout << "No";
	return 0;
}

