#include<bits/stdc++.h>
using namespace std;


int main() {
	
	int N,cnt=0;
	cin >> N;
	vector<int> h(N);
	for(int i=0; i<N; i++){
		cin >> h.at(i);
		bool flag = 1;
		for(int j=0; j<i; j++){
			if(h.at(j)>h.at(i)) flag = 0;
		}
		if(flag) cnt++;
	}
	cout << cnt << endl;
	
	
	return 0;
}