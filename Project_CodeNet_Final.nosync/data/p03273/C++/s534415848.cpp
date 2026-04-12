#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<map>
#define ran(x) (x).begin(),(x).end()
using namespace std;
int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	vector<int> a(h,0), b(w,0);
	for(int i = 0; i < h; ++i) {
		cin >> s[i];
		int cou = 0;
		for(int j = 0; j < w; ++j) {
			if(s[i][j] == '.')
				++cou;
		}
		if(cou == w)
			a[i] = 1;;
	}
	for(int j = 0; j < w; ++j) {
		int cou = 0;
		for(int i = 0; i < h; ++i) {
			if(s[i][j] == '.')
				++cou;
		}
		if(cou == h)
			b[j] = 1;
	}
	for(int i = 0; i < h; ++i) {
		if(!a[i]) {
			for(int j = 0; j < w; ++j) {
				if(!b[j])
					cout << s[i][j];
			}
			cout << endl;
		}
	}

}