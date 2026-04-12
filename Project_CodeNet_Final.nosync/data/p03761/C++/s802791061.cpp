#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<utility>
#include<numeric>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<tuple>
#include<stack>
#include<queue>
#include<functional>
#include<iterator>
#include<cmath>
#include<cctype>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const ll LINF = 1e18;

struct edge{int to,cost;};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string s[n];
	unordered_map<char,int> map[n];
	for(int i=0;i<n;i++){
		cin >> s[i];
		for(int j=0;j<s[i].size();j++){
			map[i][s[i][j]]++;
		}
	}
	int mini;
	char ans;
	for(int az=0;az<26;az++){
		mini=INF;
		ans = char(az+'a');
		for(int i=0;i<n;i++){
			mini = min(mini,map[i][ans]);
		}
		for(int i=0;i<mini;i++) cout << ans;
	}
	cout << "\n";

	return 0;
}