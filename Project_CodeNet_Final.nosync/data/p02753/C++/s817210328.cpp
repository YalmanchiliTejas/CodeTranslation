#include<bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
using namespace std;

//ループマクロ
#define FOR(i , a , b)  for(int i = (a) ; i < (b) ; i++)
#define REP(i , n)      for(int i = 0 ; i < n ; i++)
#define REPR(i , n)     for(int i = n ; 0 <= i ; i--)
#define ROP(i, n)       for(int i = 1 ; i <= n ; i++)

//入出力
#define SCOUT(x) cout << (x) << " "
#define VECCIN(x) for(auto& ele : (x) ) cin >> ele
#define VECOUT(x) for(auto& ele : (x) ) cout << ele << " "; cout << endl;

//その他
#define ALL(obj) (obj).begin() , (obj).end() 
#define SORT(obj) sort(ALL(obj))
#define GSORT(obj) sort(ALL(obj) , greater<int>())
#define P pair<int , int>
#define V vector<int>
#define VLL vector<long long>
#define M map<int, int>
#define S set<int>
#define PQ priority_queue<int>
#define PQG priority_queue<int , V , greater<int>>

int main(void) {

	ios::sync_with_stdio(false);	cin.tie(0);
    string s;  cin >> s;
    bool a_flag = false, b_flag = false;
    for(int i = 0 ; i < 3 ; i++){
      if(s[i] == 'A') a_flag = true;
      if(s[i] == 'B') b_flag = true;
    }

    if(a_flag && b_flag)  cout << "Yes" << endl;
    else                  cout << "No" << endl;
    
	return 0;
}