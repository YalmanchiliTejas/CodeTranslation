#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <list>
#include <math.h>
#include <map>
using namespace std;
#define REP(i, k, n) for(int i = k;i < n; i++)
#define rep(i, n) REP(i,0,n)
#define ll long long int
int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};
#define eps 10e-6
int cnt[51][26];
int main(void){
	int n;
	cin >> n;

	rep(i,n){
		string s;
		cin >> s;
		rep(j,s.size()){
			cnt[i][s[j]-'a']++;
		}
	}
	int ans = 0;
	rep(i,26){
		int mini = 10000000;
		rep(j,n){
			mini = min(mini, cnt[j][i]);
		}
		char c = 'a';
		rep(j,mini){
			printf("%c",c+i);
		}
	}
	cout << endl;
}
