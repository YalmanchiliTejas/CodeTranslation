#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<utility>
#include<numeric>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<tuple>
#include<stack>
#include<queue>
#include<functional>
#include<iterator>
#include<cmath>
#include<cctype>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = INF+7;

struct edge{int to,cost;};

void dump(ll *b,int n){
	for(int i=0;i<n;i++){
		cout << b[i] << " ";
	}
	cout << "\n";
}

bool judge(){

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);

	if(n%2==0){
		ll ans=0;
		ans+=a[n/2]-a[n/2-1];
		
		for(int i=0;i<(n-2)/2;i++){
			ans+=2*(a[n-1-i]-a[i]);
		}
		cout << ans << "\n";
	}else{
		ll ans1=0,ans2=0;
		ans1+=(a[n/2]+a[n/2+1]);
		ans2-=(a[n/2-1]+a[n/2]);

		int i=0;
		for(;i<(n-2)/2;i++){
			ans1+=2*a[n-1-i];
			ans1-=2*a[i];
			ans2-=2*a[i];
			ans2+=2*a[n-1-i];
		}
		ans1-=2*a[i];
		ans2+=2*a[n-1-i];
		cout << max(ans1,ans2) << "\n";
	}
	return 0;
}