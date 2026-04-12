#include<iostream>
using namespace std;

int main(void) {

	int n; 
	///入力

	while (cin >> n,n) {
	/// カンマ区切りの書き方だと0が入力された際に終了

		int top = 1, south = 2, east = 3,
			sum = 1;

		for (int i = 0;i < n;++i) {

			string s;
			cin >> s;

			if (s == "North") {
				int a = top;
				top = south;
				south = 7 - a;
			}

			else if (s == "East") {
				int a = east;
				east = top;
				top = 7 - a;
			}

			else if (s == "West") {
				int a = top;
				top = east;
				east = 7 - a;
			}

			else if (s == "South") {
				int a = south;
				south = top;
				top = 7 - a;
			}

			else if (s == "Right") {
				int a = south;
				south = east;
				east = 7 - a;
			}

			else if (s == "Left") {
				int a = east;
				east = south;
				south = 7 - a;
			}

			sum += top;

		}
		cout << sum << endl;
	}
}

