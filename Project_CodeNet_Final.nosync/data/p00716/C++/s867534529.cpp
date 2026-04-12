#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long int ll;
typedef pair<ll,ll> Pi;
const int INF=(ll)(1LL<<31)-1;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
//int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int m;
int main(){
	cin>>m;
	for(int iii=0;iii<m;iii++){
		ll im;
		cin>>im;
		ll y;
		cin>>y;
		ll n;
		cin>>n;
		ll ans=0;
		for(int kk=0;kk<n;kk++){
			ll sc,cos;
			double rate;
			cin>>sc>>rate>>cos;
			ll tim=im;
			if(sc){
				for(int i=0;i<y;i++){
					tim=tim*(1+rate);
					tim-=cos;
				}
				//cout<<tim<<endl;
				ans=max(ans,tim);
				//cout<<tim<<endl;
			}else{
				double interest=0;
				for(int i=0;i<y;i++){
					interest+=floor(tim*rate);
					tim-=cos;
				}
				tim+=interest;
				ans=max(ans,tim);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
			
