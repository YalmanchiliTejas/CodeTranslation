#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int m, n;

	while(cin >> m >> n, m || n) {
		cin.ignore();
		int nex_p[1024];
		bool f[1024];
		int plre = m;
		for(int i = 0; i < 1024; i++) {
			nex_p[i] = (i + 1) % m;
			f[i] = true;
		}

		int cur, pre;
		cur = 0;
		pre = m-1;
		for(int i = 0; i < n; i++) {
			string in;
			stringstream sstr;
			string a;
			bool flg = true;

			getline(cin,in);
			sstr << i+1;
			sstr >> a;

			if(in == "Fizz" && (i+1) % 3 == 0 && (i+1) % 5 != 0) {
				;
			}
			else if(in == "Buzz" && (i+1) % 3 != 0 && (i+1) % 5 == 0) {
				;
			}
			else if(in == "FizzBuzz" && (i+1) % 15 == 0) {
				;
			}
			else if(in == a && (i+1) % 3 && (i+1) % 5) {
				;
			}
			else {
				flg = false;
			}

			if(flg) {
				pre = cur;
			}
			else if(plre>1){
				plre--;
				nex_p[pre] = nex_p[cur];
				f[cur] = false;
			}
			cur = nex_p[cur];
		}

		/*
		for(int i = 0; i < m; i++)
			cout << nex_p[i] << " ";
		cout << endl;
		// */

		bool space = false;
		for(int i = 0; i < m; i++) {
			if(f[i]) {
				if(space)
					cout << " ";
				cout << (i+1);
				space = true;
			}
		} cout << endl;
	}
}