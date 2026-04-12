#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int main() {
	int n,cou=0,nam=0,ma=0;
	int i,j,k;
	cin >> n;
	vector<int> h(n+1,0);
	for(i = 1; i <= n; ++i) {
		cin >> h.at(i);
		ma = max(ma, h.at(i));
		if(h.at(i - 1) <= h.at(i)) {
			if(h.at(i)>=ma)
				++cou;
		}
	}
	cout << cou << endl;
}