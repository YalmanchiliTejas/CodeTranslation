#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
int main() {
	ll n;
	cin>>n;
	vector<ll>ch;
	ll no;
	cin>>no;
	ch.push_back(-1*no);
	for(ll i=0;i<n-1;i++){
		ll now;
		cin>>now;
		now*=-1;
		auto itr=lower_bound(ch.begin(),ch.end(),now+1);
		if(itr!=ch.end()){
			ch[itr-ch.begin()]=now;
		}
		else{
			ch.push_back(now);
		}
	//	sort(ch.begin(),ch.end());
	//	cout << ch.size()<<endl;
	}
	cout <<ch.size();
	// your code goes here
	return 0;
}