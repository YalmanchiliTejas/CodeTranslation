#include <bits/stdc++.h>

#define x first
#define y second

#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cerr << #x << ": " << x << endl;
#endif

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const int mod=1000000000+7;

int addm(int& a,int b) {return (a+=b)<mod?a:a-=mod;}

template<class T,class U> bool smin(T& a,U b) {return a>b?(a=b,1):0;}
template<class T,class U> bool smax(T& a,U b) {return a<b?(a=b,1):0;}

ll N,m[2],M[2];
pll boxes[200000];
ll r=LLONG_MAX;
ll dp[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	m[0]=m[1]=INT_MAX;
	for (int i=0;i<N;i++) {
		cin >> boxes[i].x >> boxes[i].y;
		if (boxes[i].x>boxes[i].y) swap(boxes[i].x,boxes[i].y);
		smin(m[0],boxes[i].x);
		smax(M[0],boxes[i].x);
		smin(m[1],boxes[i].y);
		smax(M[1],boxes[i].y);
	}

	r=(M[0]-m[0])*(M[1]-m[1]);
	DEBUG(r);

	sort(boxes,boxes+N);
	fill(dp,dp+N,boxes[N-1].x);
	ll cM=boxes[0].y;
	for (int i=1;i<N;i++) {
		smax(dp[i],cM);
		smax(cM,boxes[i].y);
	}

	ll b=LLONG_MAX;
	for (int i=0;i<N;i++) smin(b,dp[i]-min(boxes[i].x,m[1]));
	DEBUG(b);
	DEBUG(M[1]-m[0]);
	DEBUG(r);
	smin(r,(M[1]-m[0])*b);
	cout << r << endl;
}