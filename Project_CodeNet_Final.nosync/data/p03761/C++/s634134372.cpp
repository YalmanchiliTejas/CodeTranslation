#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    vector<map<char, int>> mp(N);
    rep(i, N){
        string s;
        cin >> s;
        int len = (int)s.size();
        rep(j, len){
            mp[i][s[j]]++;
        }
    }
    string ans;
    rep(i, 26){
        char word = char(i + 'a');
        int min_cnt = N + 100;
        rep(j, N){
            min_cnt = min(min_cnt, mp[j][word]);
        }
        rep(j, min_cnt) ans.push_back(word);
    }
    cout << ans << endl;
    return 0;
}