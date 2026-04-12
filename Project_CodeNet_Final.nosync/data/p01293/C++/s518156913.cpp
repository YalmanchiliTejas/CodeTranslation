#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cassert>
#include <functional>

using namespace std;

#define LOG(...) printf(__VA_ARGS__)
//#define LOG(...)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define CLR(a) memset((a), 0 ,sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int dx[] = { -1, 0, 1, 0 }; const int dy[] = { 0, 1, 0, -1 };
struct trump{
	int number;
	int mark;//S,H,C,D
};
int main() {
	char c;
	while (cin >> c, c != '#'){
		int first;
		if (c == 'S')first = 0;
		if (c == 'H')first = 1;
		if (c == 'C')first = 2;
		if (c == 'D')first = 3;
		trump player[4][13];
		REP(i, 4){
			REP(j, 13){
				string s;
				int num;
				int mark;
				cin >> s;
				if ('2' <= s[0] && s[0] <= '9'){
					num = s[0] - '0';
				}
				if (s[0] == 'T')num = 10;
				if (s[0] == 'J')num = 11;
				if (s[0] == 'Q')num = 12;
				if (s[0] == 'K')num = 13;
				if (s[0] == 'A')num = 14;

				if (s[1] == 'S')mark = 0;
				if (s[1] == 'H')mark = 1;
				if (s[1] == 'C')mark = 2;
				if (s[1] == 'D')mark = 3;
				player[i][j] = { num, mark };
			}
		}
		int ns = 0, ew = 0;

		REP(i, 13){
			int second;
			if (i == 0)
				second = player[3][0].mark;
			int count = 0;
			vector<int> vi;
			REP(j, 4){
				if (player[j][i].mark == first){
					count++;
					vi.push_back(j);
				}
			}
			if (count == 1){
				if (vi[0] % 2){
					ew++;
				}
				else{
					ns++;
				}
				if (i != 12)second = player[vi[0]][i+1].mark;
				continue;
			}
			if (count >= 2){
			int max=0;
			int pl;
				REP(j, vi.size()){
					if (max < player[vi[j]][i].number){
						max = player[vi[j]][i].number;
						pl = vi[j];
					}
				}
				if (pl % 2){
					ew++;
				}
				else{
					ns++;
				}
				if (i != 12)second = player[pl][i + 1].mark;
				continue;
			}
			count=0;
			vi.clear();
			REP(j, 4){
				if (player[j][i].mark == second){
					count++;
					vi.push_back(j);
				}
			}
			if (count == 1){
				if (vi[0] % 2){
					ew++;
				}
				else{
					ns++;
				}
				if (i != 12)second = player[vi[0]][i + 1].mark;
				continue;
			}
			if (count >= 2){
				int max = 0;
				int pl;
				REP(j, vi.size()){
					if (max < player[vi[j]][i].number){
						max = player[vi[j]][i].number;
						pl = vi[j];
					}
				}
				if (pl % 2){
					ew++;
				}
				else{
					ns++;
				}
				if (i != 12)second = player[pl][i + 1].mark;
				continue;
			}
		}
		if (ew>ns)
			cout << "EW "<<(ew%6)<<endl;
		else
			cout << "NS " << (ns % 6) << endl;
	}
}