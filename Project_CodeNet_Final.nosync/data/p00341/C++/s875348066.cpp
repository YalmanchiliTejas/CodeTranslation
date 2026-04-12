#include <bits/stdc++.h>
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
int main(){
	vector<int> a;
	REP(i,12){
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(),a.end());
	for(int i = 0;i < 12;++i){
		if(i % 4 != 3&&a[i] != a[i+1]){
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;
	return 0;
}
