/**
 *      ABC 58 C
 *      author  : kyomukyomupurin
 *      created : 2018-09-29 17:26:25
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    string S[n] = {};
    for (auto i = 0; i < n; ++i) {
        cin >> S[i];
    }
    int countC[30] = {};

    for  (char c = 'a'; c <= 'z'; ++c){
        int min = 30;
        for (auto i = 0; i < n; ++i) {
            //int min = 30;
            int x = count(S[i].begin(), S[i].end(), c);
            if (x < min) min = x;
        }
        countC[c - 'a'] = min;
    }
    string answer = {};

    for (auto c = 'a'; c <= 'z'; ++c) {
        if (countC[c - 'a'] > 0){
            for (auto i = 0; i < countC[c - 'a']; ++i) {
                answer.push_back(c);
            }
        }
    }
    cout << answer << endl;

    return 0;
}