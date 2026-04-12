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

int n;
int s[100100];
int sa[100100];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		char t;
		cin>>t;
		if(t=='o'){
			s[i]=1;
		}else{
			s[i]=-1;
		}
	}
	
	for(int i=-1;i<2;i+=2){
		for(int j=-1;j<2;j+=2){
			sa[0]=i;
			sa[1]=j;
			for(int k=2;k<n;k++){
				sa[k]=sa[k-2]*sa[k-1]*s[k-1];
				
			}
		
		
		//cout<<s[0]*sa[1]*sa[n-1]*sa[0]<<" "<<sa[n-1]*s[n-1]*sa[0]*sa[n-2]<<endl;
		if(s[0]*sa[1]*sa[n-1]*sa[0]==1&&sa[n-1]*s[n-1]*sa[0]*sa[n-2]==1){
			for(int i=0;i<n;i++){
				if(sa[i]==1){
					cout<<'S';
				}else{
					cout<<'W';
				}
			}
			cout<<endl;
			return 0;
		}
		}
	}
	cout<<-1<<endl;
	return 0;
}
					