#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <bitset>
using namespace std;
#define FOR(I,F,N) for(int I = F; I < (int)(N); I++)
#define rep(i, n) FOR(i, 0, n)
#define FIN(V) cout<<V<<endl
#define pb push_back
#define INF (1 << 30)
template<typename T>
void remove(vector<T>& vector, unsigned int index){
vector.erase(vector.begin() + index);
}
typedef pair<int, int> P;
typedef long long ll;
typedef priority_queue<int> pq;
int StrToInt(string);
string IntToStr(int);
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

map<int, string> data;
void FizzBuzz(){
	for(int i = 1; i <= 10000; i++){
		bool flag = false;
		string S;
		if(i % 3 == 0){
			S += "Fizz";
			flag = true;
		}
		if(i % 5 == 0){
			S += "Buzz";
			flag = true;
		}
		if(flag){
			data[i] = S;
		}else{
			data[i] = IntToStr(i);
		}
	}
}

int main(void){
	FizzBuzz();
	int m, n;
	while(cin >> m >> n, n||m){
		vector<int> player;
		for(int i = 1; i <= m; i++){
			player.pb(i);
		}
		int count = 0;
		for(int i = 1; i <= n; i++){
			string s;
			cin >> s;
			int safe = player.size();
			if(player.size() == 1)continue;
			if(data[i] != s){
				remove(player, count%safe);
				count %= safe;
			}else{
				count++;
			}
		}

		rep(i, player.size()){
			cout << player[i];
			if(i != player.size()-1)cout << " ";
		}
		cout << endl;
	}


	return 0;
}



int StrToInt(string s){
	stringstream ss;
	ss << s;
	int val;
	ss >> val;
	return val;
}
string IntToStr(int i){
	stringstream ss;
	ss << i;
	return ss.str();
}