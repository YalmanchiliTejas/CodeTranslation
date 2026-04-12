#include <bits/stdc++.h>
typedef long long i64;
using std::cout;
using std::endl;
using std::cin;

int main(){
	int n; cin >> n;
	std::vector<std::pair<int, int>> vec;
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		if(a > b) std::swap(a, b);
		
		vec.push_back({a, b});
	}
	sort(begin(vec), end(vec)); reverse(begin(vec), end(vec));
	
	int Ami = 1 << 30, Bmi = 1 << 30, Ama = 0, Bma = 0;
	std::vector<int> miA(n + 1, 1 << 30), maA(n + 1, 0), miB(n + 1, 1 << 30), maB(n + 1, 0);
	for(int i = n - 1; i >= 0; i--) {
		Ami = std::min(Ami, vec[i].first);
		Ama = std::max(Ama, vec[i].first);
		Bmi = std::min(Bmi, vec[i].second);
		Bma = std::max(Bma, vec[i].second);
		
		miA[i] = Ami;
		maA[i] = Ama;
		miB[i] = Bmi;
		maB[i] = Bma;
	}
	
	
	i64 ans = 1LL << 60;
	Ami = Bmi = 1 << 30, Ama = Bma = 0;
	for(int i = -1; i < n; i++) {
		if(~i) {
			Ami = std::min(Ami, vec[i].first);
			Ama = std::max(Ama, vec[i].first);
			Bmi = std::min(Bmi, vec[i].second);
			Bma = std::max(Bma, vec[i].second);
		}
		
		i64	AmiA = std::min(Ami, miB[i + 1]);
		i64	AmaA = std::max(Ama, maB[i + 1]);
		i64	BmiB = std::min(Bmi, miA[i + 1]);
		i64	BmaB = std::max(Bma, maA[i + 1]);
		
		ans = std::min(ans, (AmaA - AmiA) * (BmaB - BmiB));
	}
	
	cout << ans << endl;
	return 0;
}
