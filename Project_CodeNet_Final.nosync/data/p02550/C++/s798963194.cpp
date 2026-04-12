#include<iostream>
#include<vector>
using LL = long long;
using namespace std;

int main() {
	LL N, X, M;
	cin >> N >> X >> M;
	LL an = X, sum = 0;
	vector<LL> Sum;
	Sum.push_back(0);
	vector<LL> exsists(100010, -1);
	for(int i = 1; i<= N; i++){
		sum += an;
		Sum.push_back(sum);
		if (exsists[an] == -1) {
			exsists[an] = i;
		}
		else {
			LL l = exsists[an];
			LL r = i;
			LL Sdiff = Sum[r] - Sum[l];
			LL diff = r - l;

			LL shuki = (N - r) / diff;
			LL amari = (N - r) % diff;
			sum = sum + Sdiff * shuki + Sum[l + amari] - Sum[l];
			break;
		}
		//cout << i << "\t" << an << "\t" << sum << endl;
		an = an * an % M;
	}

	cout << sum << endl;


	return 0;
}
