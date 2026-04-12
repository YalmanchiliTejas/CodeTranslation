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
	int n;  cin >> n;
	V a(n + 1);
	for(int i = 1 ; i <= n ; i++)  cin >> a[i];

	V b;  b.push_back(-1);
  	int to, from;
  	if(n % 2)
      to = 1, from = 2;
  	else
      to = 2, from = 1;
  
	for(int i = n ; to <= i ; i -= 2)      b.push_back(a[i]);
	for(int i = from ; i <= n ; i += 2)  b.push_back(a[i]);

	for(int i = 1 ; i <= n ; i++)  SCOUT(b[i]);
	cout << endl;

	return 0;
}