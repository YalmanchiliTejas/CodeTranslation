#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define bFOR(i,n1,n2) for(int i=n1;i>=n2;i--)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long int ll;
typedef pair<ll,ll> Pi;
const int INF=(ll)(1LL<<30)-1;
const double INFd=100000000000.0;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int ddx[6]={0,1,0,-1,1,-1},ddy[6]={-1,0,1,0,1,-1};

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

string s;
int a,b,c,d;
vector<string> vv;

int main(){
	while(1){
		cin>>s;
		if(s=="#")break;
		cin>>a>>b>>c>>d;
		int w=0,h=0;
		char s1[10][10];
		REP(i,s.size()){
			if(s[i]=='/')h++;
		}
		h++;
		REP(i,s.size()){
			if(s[i]=='/')break;
			if(s[i]=='b')w++;
			if(isdigit(s[i]))w+=(s[i]-'0');
		}
		int hj=1;
		int wj=1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='/'){
				hj++;
				wj=1;
				continue;
			}else if(s[i]=='b'){
				s1[hj][wj]='b';
				wj++;
			}else{
				for(int k=0;k<s[i]-'0';k++){
					s1[hj][wj]=' ';
					wj++;
				}
			}
		}
		s1[a][b]=' ';
		s1[c][d]='b';
		string ans="";
		int co=0;
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(s1[i][j]=='b'){
					if(co!=0){
						ans+=(char)co+'0';
					}
					ans+='b';
					co=0;
				}else{
					co++;
					if(j==w){
						ans+=(char)co+'0';
						co=0;
					}
				}
			}
			if(i!=h)
			ans+='/';
		}
		vv.push_back(ans);
	}
	REP(i,vv.size())
		cout<<vv[i]<<endl;
	return 0;
}
