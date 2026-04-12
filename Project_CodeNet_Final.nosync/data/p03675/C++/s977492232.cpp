#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[200005];

int main(){
	cin >> n;
	for(long long i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<long long> ans;
	if(n%2 == 0){
		for(long long i = n - 1; i >= 0; i-=2){
			ans.push_back(a[i]);
		}
		for(long long i = 0; i < n; i+=2){
			ans.push_back(a[i]);
		}
	}else{
		for(long long i = n - 1; i >= 0; i-=2){
			ans.push_back(a[i]);
		}
		for(long long i = 1; i < n; i+=2){
			ans.push_back(a[i]);
		}
	}

	for(long long i = 0; i < ans.size(); i++){
		cout << ans[i];
		if(i != ans.size() - 1){
			cout << " ";
		}
	}
	cout << endl;
}

