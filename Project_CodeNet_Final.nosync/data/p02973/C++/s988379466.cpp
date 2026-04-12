#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	int n;
	cin>>n;
	vector<ll>v(n);
	multiset<ll> s;
	for(int i=0;i<n;i++){
		scanf("%lld", &v[i]);
	}
	s.insert(v[0]);
	for(int i=1; i<n;i++){
		auto it = s.lower_bound(v[i]);
		if(!(it==s.begin())){
			it--;
			s.erase(it);
		}
		s.insert(v[i]);
	}
	cout<<s.size()<<endl;
}