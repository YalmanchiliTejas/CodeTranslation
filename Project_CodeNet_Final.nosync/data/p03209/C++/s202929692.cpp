#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
//#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef pair<int,int> Pi;
typedef long long int ll;
const int INF=(ll)(1LL<<31)-1;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll n,x;

ll layer[51];
ll patty[51];

ll burger(ll nn,ll xx){
	if(nn==0){
		return 1;
	}
	else if(xx==1){
		return 0;
	}
	else if(xx<=1+layer[nn-1]){
		return burger(nn-1,xx-1);
	}
	else if(xx==layer[nn-1]+2){
		return patty[nn-1]+1;
	}
	else if(xx<layer[nn]){
		return patty[nn-1]+1+burger(nn-1,xx-layer[nn-1]-2);
	}
	else{
		return patty[nn];
	}
}
	

int main(){
	cin>>n>>x;
	layer[0]=1,patty[0]=1;
	for(int i=1;i<=50;i++){
		layer[i]=layer[i-1]*2+3;
		patty[i]=patty[i-1]*2+1;
	}
	cout<<burger(n,x)<<endl;
	return 0;
}