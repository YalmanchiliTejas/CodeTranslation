#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> d(n);
	for(int i=0;i<n;i++){
		cin >> d[i];
	}
	int now=0;
	for(int i=0;i<n;i++){
		if(now<i){
			cout << "no" << endl;
			return 0;
		}
		now=max(now,i+d[i]/10);
	}
	now=0;
	reverse(d.begin(),d.end());
	for(int i=0;i<n;i++){
		if(now<i){
			cout << "no" << endl;
			return 0;
		}
		now=max(now,i+d[i]/10);
	}
	cout << "yes" << endl;
}

