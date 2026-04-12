#include<bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
using namespace std;

//ループマクロ
#define FOR(i , a , b)  for(int i = (a) ; i < (b) ; i++)
#define REP(i , n)      for(int i = 0 ; i < n ; i++)
#define REPR(i , n)     for(int i = n ; 0 <= i ; i--)

//入出力
#define SCOUT(x) cout << (x) << " "
#define VECCIN(x) for(auto& ele : (x) ) cin >> ele
#define VECOUT(x) for(auto& ele : (x) ) cout << ele << " "; cout << endl;

//その他
#define ALL(obj) (obj).begin() , (obj).end() 
#define P pair<int , int>
#define V vector<int>
#define M map<int, int>
#define S set<int>
#define PQ priority_queue<int>
#define PQG priority_queue<int , V , greater<int>>
int main(void) {

	ios::sync_with_stdio(false);	cin.tie(0);
	int H, W;  cin >> H >> W;
	char field[10][10];
	for(int i = 0 ; i < 10 ; i++)
	 for(int j = 0 ; j < 10 ; j++)
	  field[i][j] = 0;

	for(int i = 1 ; i <= H ; i++)
	 for(int j = 1 ; j <= W ; j++)
	  cin >> field[i][j];

	bool ans = true;
	for(int i = 1 ; i <= H ; i++){
	 for(int j = 1; j <= W ; j++){
	  if(field[i][j] == '#'){

		if(field[i][j - 1] == '#' && field[i - 1][j] == '#')
		 ans = false;

		if(field[i][j + 1] == '#' && field[i + 1][j] == '#')
		 ans = false;
	  }
	 }
	}

	if(ans) cout << "Possible" << endl;
	else    cout << "Impossible" << endl;

	return 0;
}