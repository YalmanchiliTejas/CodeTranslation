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
	map<char, ll>  mp, keepmp;
  	for(char i = 'a' ; i <= 'z' ; i++)  mp[i] = INF;
  
	for(int i = 0 ; i < n ; i++){
      
      	for(char j = 'a' ; j <= 'z' ; j++)  keepmp[j] = 0;
		string input;  cin >> input;
		for(int j = 0 ; j < input.size() ; j++)
			keepmp[input[j]] += 1;
      
        for(char j = 'a' ; j <= 'z' ; j++)
            mp[j] = min(mp[j], keepmp[j]);
	}

	string ans;
	for(char i = 'a' ; i <= 'z' ; i++)
		for(int j = 0 ; j < mp[i] ; j++)
          ans += i;

	cout << ans << endl;

	return 0;
}