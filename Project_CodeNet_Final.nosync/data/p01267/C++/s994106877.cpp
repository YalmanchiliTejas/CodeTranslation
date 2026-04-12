#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define bFOR(i,n1,n2) for(int i=n1;i>=n2;i--)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long int ll;
typedef pair<int,int> Pi;
const int INF=(ll)(1LL<<30)-1;
const double INFd=100000000000.0;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int n,a,b,c,x;
queue<int> y;

int main(){
	while(1){
		while(y.size())y.pop();
		cin>>n>>a>>b>>c>>x;
		if(n==0&&a==0&&b==0&&c==0&&x==0)break;
		REP(i,n){
			int t;
			cin>>t;
			y.push(t);
		}
		int cou=0;
		while(cou<=10000){
			if(x==y.front())y.pop();
			if(y.empty())break;
			x=(a*x+b)%c;
			cou++;
		}
		if(cou==10001)cout<<-1<<endl;
		else cout<<cou<<endl;
	}
	return 0;
}
