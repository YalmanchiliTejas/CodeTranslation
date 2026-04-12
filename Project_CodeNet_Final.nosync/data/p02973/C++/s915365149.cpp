#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	for(auto &i:A)cin >> i;
	int ans=1;
	multiset<int> m;
	m.insert(A[0]);
	
	for(int i=1;i<N;i++){
		
		auto it=m.lower_bound(A[i]);
		if(it==m.begin()){
			ans++;
			m.insert(A[i]);
		}
		else{
			it--;
			m.erase(it);
			m.insert(A[i]);
		}
	}
	cout << ans << endl;
	return 0;
}