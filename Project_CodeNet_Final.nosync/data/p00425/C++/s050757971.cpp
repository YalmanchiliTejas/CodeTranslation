#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <fstream>
//#include <tuple>
#include <set>
#include <string.h>
#include <functional>

#define X first
#define Y second
#define MP make_pair
//#define MT make_tuple
#define REP(i, a, n) for(int (i) = (a); (i) < (n); ++(i))
#define FOR(i, n) REP(i, 0, n)
typedef long long ll;
using namespace std;
const int MAX = 101;

template<class T, class U>
void convert(T &t, U &u)
{
	stringstream ss;
	ss << t;
	ss >> u;
}

void North(int* data)
{
	int tmp = data[5];
	data[5] = data[0];
	data[0] = data[2];
	data[2] = data[4];
	data[4] = tmp;
}

void East(int* data)
{
	int tmp = data[5];
	data[5] = data[3];
	data[3] = data[2];
	data[2] = data[1];
	data[1] = tmp;
}

void West(int* data)
{
	int tmp = data[5];
	data[5] = data[1];
	data[1] = data[2];
	data[2] = data[3];
	data[3] = tmp;
}

void South(int* data)
{
	int tmp = data[5];
	data[5] = data[4];
	data[4] = data[2];
	data[2] = data[0];
	data[0] = tmp;
}

void Right(int* data)
{
	int tmp = data[0];
	data[0] = data[1];
	data[1] = data[4];
	data[4] = data[3];
	data[3] = tmp;
}

void Left(int* data)
{
	int tmp = data[0];
	data[0] = data[3];
	data[3] = data[4];
	data[4] = data[1];
	data[1] = tmp;
}

int main()
{
	int n;
	while (cin >> n && n){
		int data[] = { 5, 4, 1, 3, 2, 6 };

		int ans = 0;
		FOR(i, n){
			ans += data[2];

			string a; cin >> a;
			
			if (a == "North"){
				North(data);
			}
			else if (a == "East"){
				East(data);
			}
			else if (a == "West"){
				West(data);
			}
			else if (a == "South"){
				South(data);
			}
			else if (a == "Right"){
				Right(data);
			}
			else if (a == "Left"){
				Left(data);
			}
		}
		ans += data[2];

		cout << ans << endl;
	}

	return 0;
}