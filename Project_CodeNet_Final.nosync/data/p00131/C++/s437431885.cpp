#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <complex>
#include <fstream>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T> T RoundOff(T a){ return int(a+.5-(a<0)); }
template<class T, class C> void chmax(T& a, C b){ if(a < b) a = b; }
template<class T, class C> void chmin(T& a, C b){ if(b < a) a = b; }
template<class T, class C> pair<T, C> mp(T a, C b){ return make_pair(a, b); }

const int dx[] = {0, 0, 0, 1, -1};
const int dy[] = {0, 1, -1, 0, 0};

void reverse(vector<vint>& board, int x, int y)
{
	rep(i, 5)
	{
		int nx = x + dx[i], ny = y + dy[i];
		
		if(0 <= nx && nx < 10 && 0 <= ny && ny < 10)
			board[nx][ny] = !board[nx][ny];
	}
}


void bitinitialize(vector<vint>& board, vector<vint>& ans, int bit)
{
	rep(i, 10) if(bit & 1 << i)
	{
		reverse(board, i, 0);
		ans[i][0] = 1;
	}
}


void fill(vector<vint>& board, vector<vint>& ans)
{
	REP(y, 1, 10) rep(x, 10)
	{
		if(board[x][y-1])
		{
			reverse(board, x, y);
			ans[x][y] = 1;
		}
	}
}


bool check(vector<vint>& board)
{
	rep(i, 10) rep(j, 10)
		if(board[i][j]) return false;
	
	return true;
}


int main()
{
    int n;
	cin >> n;
	
	while(n--)
	{
		vector<vint> answer(10, vint(10));
		
		rep(y, 10) rep(x, 10)
			cin >> answer[x][y];
		
		rep(bit, 1 << 10)
		{
			vector<vint> board(answer);
			vector<vint> ans(10, vint(10, 0));
			
			bitinitialize(board, ans, bit);
			
			fill(board, ans);
						
			if(check(board))
			{
				rep(y, 10) rep(x, 10)
					cout << ans[x][y] << (x == 9 ? "\n" : " ");
				
				break;
			}
		}
	}
}