#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;i<(n);i++)
#define REP(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define INF LLONG_MAX - 100
#define MOD 1000000007
#define fcout cout << fixed << setprecision(15)
#define int long long
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)?"YES":"NO")
#define sec second
#define fir first
typedef long long ll;
typedef pair<int, int> P;
typedef priority_queue<int> pque;
typedef vector<int> Vec;
int gcd(int a,int b){return b?gcd(b,a%b):a;};
int lcm(int a,int b){return a/gcd(a,b)*b;};
int mod(int a,int b){return (a+b-1)/b;};
template<typename A, size_t N, typename T>
void Fill(A(&array)[N],const T &val){std::fill((T*)array,(T*)(array+N),val);}
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;};
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;};



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
	long long ans=0;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	for(int i=0; i<n; i++){
		if(n%2==0){
			if(i+1==n-1-i){
				ans+=a[n-1-i]-a[i];
				break;
			}else {
				ans+=2*(a[n-1-i]-a[i]);
			}
		}else {
			if(i+2==n-1-i){
				ans+=max(2*a[i+2]-a[i+1]-a[i],a[i+2]+a[i+1]-a[i]*2);
				break;
			}else {
				ans+=2*(a[n-1-i]-a[i]);
			}
		}
	}
	cout << ans << endl;
    return 0;
}