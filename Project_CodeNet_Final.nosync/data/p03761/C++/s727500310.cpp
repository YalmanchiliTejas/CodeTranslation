
// Problem : C - Dubious Document
// Contest : AtCoder - AtCoder Beginner Contest 058
// URL : https://atcoder.jp/contests/abc058/tasks/arc071_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;

string check(string s1, string s2){
    string ans = "";
    int n1 = s1.size(), n2 = s2.size();
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(s1[i]==s2[j]){
                s2[j] = '?';
                ans+=s1[i];
                break;
            }
        }
    }
    return ans;
}

int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string ans,s;
	unordered_map<int, int> m;
	for(int i = 0; i < n; ++i){
	    cin >> s;
	    if(i==0){
	        ans = s;
	    }
	    else{
	        ans = check(ans, s);
	    }
	}
	sort(ans.begin(), ans.end());
	cout << ans;
	//cout << check("aaa","aa");
	return 0;
}