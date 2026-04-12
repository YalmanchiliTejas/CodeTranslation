#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, string> P;
bool comp(P a, P b){
	return a.first > b.first;
}

int main(){
	string s;
	int n, w, l, d, f = 0;
	while(cin >> n, n){
		if(f)cout << endl;f = 1;
		vector<P> v;
		for(int i = 0;i < n;i++){
			cin >> s >> w >> l >> d;
			int x = w*3 + d;
			v.push_back(P(x, s));
		}
		sort(v.begin(), v.end(), comp);
		for(int i = 0;i < n;i++){
			cout << v[i].second << "," << v[i].first << endl;
		}
	}
	return 0;
}