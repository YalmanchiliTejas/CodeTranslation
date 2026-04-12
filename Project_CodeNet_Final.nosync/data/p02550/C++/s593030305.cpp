#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include<random>
#include <bitset>
#include <deque>
using namespace std;
//#define N (1000000000+7)
#define N 998244353
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> Q;
typedef vector<ll> vec;
typedef vector<vec> mat;
const int inf = (int)1e9; 
 
ll gcd(ll a, ll b) {
	if (b > a) {
		ll tmp = b;
		b = a;
		a = tmp;
	}
	if (a%b == 0)return b;
	else return gcd(b, a%b);
}


int main(void){
	ll n,x,m;
	cin>>n>>x>>m;
	if(x==0){
		cout<<0<<endl;
		return 0;
	}
	if(x==1){
		cout<<n<<endl;
		return 0;
	}
	set<ll>s1;
	vector<ll>s;
	ll t = x;
	while(true){
		if(s1.count(t)==0){
			s1.insert(t);
			s.push_back(t);
		}
		else break;
		t = (t*t)%m;
		//cout<<t<<endl;
	}
	if(t==0){
		ll ans = 0;
		ll num = 0;
		for(auto y:s){
			ans+=y;
			num++;
			if(num==n){
				cout<<ans<<endl;
				return 0;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	vector<ll>seq;
	bool flag = false;
	ll ans = 0;
	ll num = 0;
	for(int i=0;i<s.size();i++){
		int y = s[i];
		if(flag){
			seq.push_back(y);
		}
		else{
			if(y==t){
				seq.push_back(y);
				flag = true;
			}
			else{
				ans+=y;
				num++;
				if(num==n){
					cout<<ans<<endl;
					return 0;
				}
			}
		}
	}
	vector<ll>sum(seq.size()+1);
	for(ll i=0;i<seq.size();i++){
		sum[i+1] = sum[i]+seq[i];
	}
	n-=num;
	ll R = seq.size();
	ll ti = n/R;
	ll q = n%R;
	cout<<ans+sum[R]*ti+sum[q]<<endl;
	return 0;
}
