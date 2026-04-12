#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int p, s;
	char comma;
	vector<pair<int, int> > v;
	while (cin >> p >> comma >> s, p != 0 || s != 0) {
		v.push_back(pair<int, int>(s, p));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());//?????°????????????????????????
	/*
		cout << "--------------------------------" << endl;
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].first << "   " << v[i].second << endl;
		}
		cout << "--------------------------------" << endl;
	*/
	int input;
	int score = 0;
	while (cin >> input) {
		//input????????????
		for (int i = 0; i < v.size(); i++) {
			if (v[i].second == input) {
				score = v[i].first;
			}
		}
		//??????
		int cnt = 1;
		int k = -1000;
		for (int i = 0; i < v.size(); i++) {
			if (score == v[i].first) {//?±???????score????????´
				cout << cnt << endl;
				break;
			}
			if (k != v[i].first) {//score != v && ???????????????????????????
				k = v[i].first;
				cnt++;
			}
		}

	}

	return 0;
}