#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>

#define INF 1000000007
#define LINF 1000000000000000007

using namespace std;

typedef long long Int;
typedef pair<Int, Int> P;

Int gcd(Int x, Int y){
	if(y == 0)
		return x;
	return gcd(y, x % y);
}

Int lcm(Int x, Int y){
	return x * y / gcd(x, y);
}

int n;
string s[51];
int c[51][26] = {0};
int ans[26];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	
	for(int i  = 0; i < 26; i++)
		ans[i] = INF;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < s[i].size(); j++){
			c[i][s[i][j] - 'a']++;
		}
		for(int j = 0; j < 26; j++){
			ans[j] = min(ans[j], c[i][j]);
		}
	}
	
	for(int i = 0; i < 26; i++){
		if(ans[i] == 0) continue;
		for(int j = 0; j < ans[i]; j++){
			cout << (char)('a' + i);
		}
	}
	cout << endl;
	
	return 0;
}