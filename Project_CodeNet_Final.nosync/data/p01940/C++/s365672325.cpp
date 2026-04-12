#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	std::ifstream in("in");
	std::cin.rdbuf(in.rdbuf());
#endif

	string T, P;
	cin >> T >> P;
	int N = T.size(), M = P.size();

	vector<int> ans1, ans2;
	int n = 0;
	for(int i = 0; i < N; i++){
		if(T[i] == P[n]){
			ans1.push_back(i);
			n++;
			if(n == M) break;
		}
	}
	n = M - 1;
	for(int i = N - 1; i >= 0; i--){
		if(T[i] == P[n]){
			ans2.push_back(i);
			n--;
			if(n == -1) break;
		}
	}

	reverse(ans2.begin(), ans2.end());
	if(ans1.size() == P.size() && ans1 == ans2){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
}