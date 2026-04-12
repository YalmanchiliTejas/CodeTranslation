#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007

int main(){
	ll k,a,b;
	cin >> k >> a >> b;
	if(a-b<=0){
		if(k>a){
			cout << -1 << endl;
		}else{
			cout << 1 << endl;
		}
		return 0;
	}
	ll s = 0;
	ll ans = 0;
	ans = (k-a)/(a-b);
	s = (a-b)*ans;
	ans *=2;
	for(ll i=0;i<1000000;i++){
		if(i%2==0){
			ans++;
			s += a;
			if(s>=k){
				cout << ans << endl;
				return 0;
			}
		}else{
			ans++;
			s -= b;
		}
	}
	return 0;
}