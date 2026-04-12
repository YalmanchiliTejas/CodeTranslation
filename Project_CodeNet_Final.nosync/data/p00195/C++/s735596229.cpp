#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	enum tol { a, b, c, d, e };
	vector<tol>l;
	vector<int>ll;
	int a1, a2;
	while (cin >> a1 >> a2){
		if (a1 == 0 && a2 == 0)break;
		int o[5];
		int oo[5];
		a1 += a2;
		o[0] = a1;
		for (int i = 1; i < 5; i++) {
			cin >> a1 >> a2;
			a1 += a2;
			o[i] = a1;
		}
		for (int i = 0; i < 5; i++)oo[i] = o[i];
		sort(oo, oo + 5);
		if (oo[4] == o[0]) {
			l.push_back(a);
			ll.push_back(o[0]);
		}
		else if (oo[4] == o[1]) {
			l.push_back(b); 
			ll.push_back(o[1]);
		}
		else if (oo[4] == o[2]) { 
			l.push_back(c); 
			ll.push_back(o[2]);
		}
		else if (oo[4] == o[3]) { 
			l.push_back(d);
			ll.push_back(o[3]);
		}
		else if (oo[4] == o[4]) {
			l.push_back(e);
			ll.push_back(o[4]);
		}
	}
	for (int p = 0; p < l.size();p++){
		if (l[p] == a)cout << "A";
		else if (l[p] == b)cout << "B";
		else if (l[p] == c)cout << "C";
		else if (l[p] == d)cout << "D";
		else if (l[p] == e)cout << "E";
		cout << ' ' << ll[p] << endl;
	}
	char ch;
	cin >> ch;
}