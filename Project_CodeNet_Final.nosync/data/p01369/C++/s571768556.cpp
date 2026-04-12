#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <queue>

#pragma warning( disable: 4996 )

using namespace std;

typedef long long ll;

#define INF 1000000000
#define EPS 1e-10

string str;

vector<int> ans_list;

string r = "yuiophjklnm";

int main(){

	while (true){

		cin >> str;
		if (str == "#")
			break;

		int ans = 0;
		bool right = false;

		for (int i = 0; i < str.length(); i++){
			if (i == 0){
				for (int j = 0; j < r.length(); j++){
					if (str[i] == r[j])
						right = true;
				}
			}

			else if (right){
				bool flag = false;
				for (int j = 0; j < r.length(); j++){
					if (str[i] == r[j])
						flag = true;
				}
				if (!flag){
					right = false;
					ans++;
				}
			}

			else{
				bool flag = false;
				for (int j = 0; j < r.length(); j++){
					if (str[i] == r[j])
						flag = true;
				}
				if (flag){
					right = true;
					ans++;
				}
			}

		}

		ans_list.push_back(ans);

	}

	for (int i = 0; i < ans_list.size(); i++){
		cout << ans_list[i] << endl;
	}

	return 0;

}