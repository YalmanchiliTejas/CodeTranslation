#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,x,m;
	cin >> n >> x >> m;
	vector<long long> ar;
	set<long long> st;
	ar.push_back(x);
	st.insert(x);
	long long nx = (x*x)%m;
	while(!st.count(nx)){
		ar.push_back(nx);
		st.insert(nx);
		nx = (nx*nx)%m;
	}
	long long l;
	for(l=0;l<ar.size();l++){
		if(ar[l] == nx){
			break;
		}
	}
	long long ans = 0;
	for(int i=0;i<min(n,l);i++){
		ans += ar[i];
	}
	n -= min(n,l);
	long long sum = 0;
	int left = n%(ar.size()-l);
	for(int i=0;i<(ar.size()-l);i++){
		if(i < left){
			ans += ar[i+l];
		}
		sum += ar[i+l];
	}
	ans += (n/(ar.size()-l))*sum;
	cout << ans << '\n';
}