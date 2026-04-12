

#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
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

int n;
ll a[100100];

int main(){
	cin>>n;
	REP(i,n)
		cin>>a[i];
	sort(a,a+n);
	ll sum=0;
	
	if(n%2==0){
		for(int i=0;i<n/2-1;i++){
			sum+=(-2)*a[i];
		}
		sum-=a[n/2-1];
		sum+=a[n/2];
		for(int i=n/2+1;i<n;i++){
			sum+=2*a[i];
		}
	}
	ll suma=0;
	ll sumb=0;
	if(n==3){
		cout<<max(a[2]+a[1]-a[0]*2,2*a[2]-a[1]-a[0])<<endl;
		return 0;
	}
	if(n%2==1){
		vector<int> v;
        REP(i,n)v.push_back(abs(a[i]-a[n/2]));
        sort(v.begin(),v.end());
        for(auto x:v)sum+=2*x;
        sum-=min(a[n/2]-a[n/2-1],a[n/2+1]-a[n/2]);
		
	}
	cout<<sum<<endl;
	return 0;
}
		