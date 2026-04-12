#include<bits/stdc++.h>
#include<vector>
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
#define CEVCOUT(x) for(auto& ele : (x) ) cout << ele << " "; cout << endl;

//その他
#define ALL(obj) (obj).begin() , (obj).end() 
#define P pair<int , int>
#define V vector<int>
#define M map<int>
#define S set<int>
#define PQ priority_queue<int>
#define PQG priority_queue<int , V , greater<int>>

int main(void){

  string s;   cin >> s;
  for(int i = 0 ; i < s.size() - 1 ; i++){
	if(s[i] == 'A' && s[i + 1] == 'C'){
		cout << "Yes" << endl;
      	return 0;
    }
  }
  
  cout << "No" << endl;
  return 0;
}
