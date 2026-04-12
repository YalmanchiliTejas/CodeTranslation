#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    int n;  cin >> n;
    vector<string>s(n);
    vector<vector<int> >dic(n, vector<int>(26));    //文字列のそれぞれの小文字の数
    rep(i, n){
	cin >> s[i];
	rep(j, s[i].size()){
	    dic[i][s[i][j]-'a']++;
	}
    }
    rep(i, 26){
	int count=50;	//小文字の最大の数
	rep(j, n){
	    count=min(count, dic[j][i]);
	}
	rep(j, count)	printf("%c", (char)('a'+i));
    }
    printf("\n");
}
