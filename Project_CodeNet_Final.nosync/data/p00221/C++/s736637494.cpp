#include <bits/stdc++.h>
using namespace std;
int m, n; string s; vector<int> vec;
int main() {
	while(cin >> m >> n,m) {
    int cnt = 0;
    vec.clear();
		for(int i=1; i<=m; i++) vec.push_back(i);
		for(int i=1; i<=n; i++) {
			cin >> s;
			if(i%15 == 0) {
				if(s != "FizzBuzz" && vec.size()-1) vec.erase(vec.begin()+cnt);
				else cnt++;
			}
			else if(i%3 == 0) {
				if(s != "Fizz" && vec.size()-1) vec.erase(vec.begin()+cnt);
				else cnt++;
			}
			else if(i%5 == 0) {
				if(s != "Buzz" && vec.size()-1) vec.erase(vec.begin()+cnt);
				else cnt++;
			}
			else {
				if(s != to_string(i) && vec.size()-1) vec.erase(vec.begin()+cnt);
				else cnt++;
			}
			cnt %= vec.size();
		}
		for(int i=0; i<vec.size(); i++) {
			if(i) cout << " ";
			cout << vec[i];
		}
		cout << endl;
	}
}
