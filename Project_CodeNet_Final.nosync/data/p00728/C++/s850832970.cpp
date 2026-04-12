#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF=1000000000LL;
const ll MOD=1000000007LL;
const ll MAX=100010;
int main(){
	int n;
	while(cin>>n,n){
		int ma=0;
		int mi=INF;
		int sum=0;
		for(int i=0;i<n;i++){
			int s;
			cin>>s;
			sum+=s;
			ma=max(s,ma);
			mi=min(s,mi);
		}
		cout<<(sum-ma-mi)/(n-2)<<endl;
	}
	return 0;
}

