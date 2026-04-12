#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <deque>
#define WMAX 10000
#define HMAX 10000

//コメントアウトするとdebug()を実行しない
#define DEBUG

using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

typedef pair<int ,int > P;
typedef long long ll;

string ans;
char c;
string S = "aiueo";
static const int dx[8] = {0,1,1,1,0,-1,-1,-1},
					dy[8] = {1,1,0,-1,-1,-1,0,1};

string solve(){
	for (int i = 0; i < 5; ++i)
	{
		if(c == S[i]){
			return "vowel";
		}
	}
	return "consonant";
}

void answer(){
	cout << ans << "\n";
}

int main(){
	cin >> c;
	ans = solve();
	answer();
	return 0;
}