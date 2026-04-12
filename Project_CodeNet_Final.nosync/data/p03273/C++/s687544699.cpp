
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int count_s(string s) 
{
	int cnt = 0;
	for (int si = 0; si < s.length(); si++) {
		if (s[si] == '#') cnt++;
	}
	return cnt;
}

int main()
{

	int H, W;

	cin >> H >> W;

	vector<string> data;

	string line;
	for (int hi = 0; hi < H; hi++) {
		cin >> line;
		if (count_s(line) > 0) data.push_back(line);
	}

	vector<int> cnts = vector<int>(W, 0);
	for (int wi = W - 1; wi >= 0; wi--) {
		for (int hi = 0; hi < data.size(); hi++) {
			if (data[hi][wi] == '#') cnts[wi]++;
		}
	}

	vector<string> ans;
	for (int hi = 0; hi < data.size(); hi++) {
		string buf = "";
		for (int wi = 0; wi < cnts.size(); wi++) {
			if (cnts[wi] > 0) buf += data[hi][wi];
		}
		ans.push_back(buf);
	}

	for (int hi = 0; hi < ans.size(); hi++) {
		printf("%s\n", ans[hi].c_str());
	}


	//printf("%d", ans);

    return 0;
}

