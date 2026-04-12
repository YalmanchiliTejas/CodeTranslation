#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<iomanip>
#include<functional>
#include<limits>
#include <unordered_map>
#include <numeric>
#include <array>
#include <queue>
#include <chrono>

using namespace std;
using  ull = unsigned long long int;

#define rep(i,n,m) for(long long int i=n;i<(long long int)(m);i++)
#define INF (1<<29)


int main() {


	
	string str;

	cin >> str;

	rep(i, 0, str.length()) {

		if (str[i] == 'A') {

			if (i < str.length() - 1) {
				if (str[i + 1] == 'C') {
					cout << "Yes" << endl;
					return 0;
				}
			}

		}

	}



	cout << "No" << endl;




			

	return 0;
}

