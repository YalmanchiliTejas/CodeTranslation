#include <bits/stdc++.h>
using namespace std;

#define itn int
#define vi vector<int>
#define pb push_back
#define srt sort(v.begin(), v.end())
#define retunr return

//int infiint = std::numeric_limits<int>::max();
//float infiflt = std::numeric_limits<float>::infinity();


int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "rt", stdin);

    string s;
    cin >> s;
    bool ok=0;
    for(int i=0; i<2; i++) {
    	if(s[i] != s[i+1]) {
    		cout << "Yes";
    		return 0;
    	}
    }

    cout << "No";
    return 0;
}
