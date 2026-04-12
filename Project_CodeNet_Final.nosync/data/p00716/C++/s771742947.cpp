#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
double EPS=1e-10;
int INF=1e9;
int MOD=1000000007;
int main(){
	int m;
	cin>>m;
	while(m--){
		int n,init,type,year,comm;
		double rate;
		cin>>init>>year>>n;
		int ans=0;
		while(n--){
			cin>>type>>rate>>comm;
			int now=init;
			if(type){
				REP(i,year){
					now=now*rate+now-comm;
				}
			}else{
				int sum=0;
				REP(i,year){
					sum+=now*rate;
					now-=comm;
				}
				now+=sum;
			}
			ans=max(ans,now);
		}
		cout<<ans<<endl;
	}
}