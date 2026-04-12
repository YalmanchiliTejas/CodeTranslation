#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, m;
	while(cin >> m >> n, m || n) {
		vector<int> nex;

		nex.resize(m);
		for(int i = 0; i < m; i++) nex[i] = (i+1) % m;
		int pre = nex.size()-1;
		int p = 0;
		int cnt = nex.size();
		for(int t = 1; t <= n; t++) {
			string str;
			cin >> str;
			if(cnt == 1) continue;
			bool flg = false;
			int num = 0;
			flg = (str == "Fizz") || (str == "Buzz") || (str == "FizzBuzz");
			if(!flg) {
				flg = true;
				for(int i = 0; i < str.size(); i++) {
					num *= 10;
					num += str[i] - '0';
					flg &= '0' <= str[i] && str[i] <= '9';
				}
			}

			if(flg) {
				if(t%15==0)
					flg = str == "FizzBuzz";
				else if(t%3==0)
					flg = str == "Fizz";
				else if(t%5==0)
					flg = str == "Buzz";
				else
					flg = num == t;

			}

			if(flg) {
				pre = p;
				p = nex[p];
			}
			else {
				nex[pre] = nex[p];
				int tmp = p;
				p = nex[p];
				nex[tmp] = -1;
				cnt--;
			}
		}

		bool f = false;
		for(int i = 0; i < nex.size(); i++) {
			if(nex[i]+1) {
				if(f) cout << " ";
				f = true;
				cout << i+1;
			}
		}
		cout << endl;
	}
}