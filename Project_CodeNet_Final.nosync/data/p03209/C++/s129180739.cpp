#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define all(n) (n).begin(),(n).end()
typedef long long ll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}else{return 0;}}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}else{return 0;}}
template <class T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <class T> inline T LCM(T a,T b){return a*b/GCD(a,b);}

int main(){
	ll n,x;
	cin >> n >> x;
	ll p[100],b[100],pb[100];
	p[0]=1;b[0]=0;pb[0]=1;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]*2+1;
		b[i]=b[i-1]*2+2;
		pb[i]=p[i]+b[i];
	}
	ll sum=0,ans=0,cnt=n;
	while(sum!=x){
		if(sum+pb[cnt]<=x){
			sum+=pb[cnt];
			ans+=p[cnt];
			if(sum+1<=x){
				sum++;
				ans++;
			}
		}else{
			cnt--;
			sum++;
		}
	}

	cout << ans << endl;


}