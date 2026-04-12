#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <utility> 

#define rep(i,m,n) for(int i = m;i < n;++i)
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;




int main(){
	string str = "abcdefghijklmnopqrstuvwxyz";
	int n;
	cin >> n;

	int data[50][26];

	rep(i, 0, 50)rep(j, 0, 26)data[i][j] = 0;


	char ch[51];
	rep(i, 0, n) {
		scanf("%s", ch);
		rep(j, 0, strlen(ch)) {
			data[i][ch[j]-'a']++;
		}
	}

	rep(j, 0, 26) {
		vector<int> v;
		rep(i, 0, n) {
			v.push_back(data[i][j]);
		}
		sort(v.begin(), v.end());
		rep(k,0,v[0]) {
			cout << str[j];
		}
	}
	cout << endl;




	return 0;
}

