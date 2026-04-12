#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> A;
	rep(i, N) {
		int a;
		cin >> a;
		A.push_back(a);
	}

	multiset<int> ms;

	for(int i = 0; i < N; i++){
		if(ms.size() == 0 || A[i] <= *ms.begin()){
			ms.insert(A[i]);
		}else{
			auto itr = ms.lower_bound(A[i]);
			itr--;
			ms.insert(A[i]);
			ms.erase(itr);
		}
	}

	cout << ms.size() << endl;
}
