/* ***********************************************
Author        :pkwv
Created Time  :2017年10月22日 星期日 20时04分47秒
File Name     :A.cc
************************************************ */

#include <algorithm>
#include <bitset>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
  string s;
	while (std::cin >> s) {
		bool ok{false};
		for (int i = 1; i < s.size(); ++ i) {
			if (s[i - 1] == 'A' && s[i] == 'C') {
				ok = true;
			}
		}
		printf("%s\n", ok ? "Yes" : "No");
	}
  return 0;
}
