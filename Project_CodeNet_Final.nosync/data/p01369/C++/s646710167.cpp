#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
int main() {
	string a;
	string b = "yuiophjklnm";
	while (cin >> a&&a != "#") {
		int c,sum=0;
		bool l = false;
		for (int i = 0; i < a.length(); i++) {
			l = false;
			for (int j = 0; j < b.length(); j++) {
				if (a[i] == b[j]) {
					l = true;
					break;
				}
			}
			if (l) {
				if(i!=0&&c!=2){
					sum++;
				}
				c = 2;
			}
			else {
				if (i != 0 && c != 1)
					sum++;
				c = 1;
			}
		}
		cout << sum << endl;
	}
}