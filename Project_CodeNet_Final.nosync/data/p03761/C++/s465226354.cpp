#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;



int main () {

    int n;
    cin >> n;

    vector<string> s;
    string temp;

    for (int i = 0; i < n; i++){
        cin >> temp;
        s.push_back(temp);
    }
    
    // find the lexigraphical smallest common substring among all strings

    // lexigraphical_compare

    // find character in common, count them

    // only 50 x 50

    int alph_cnt[50][26];

    for (int i = 0; i < 50; i++){
        for (int j = 0; j < 26; j++){
            alph_cnt[i][j] = 0;
        }
    }

    for (int i = 0; i < s.size(); i++){
        for (int j = 0; j < s[i].size(); j++){
            alph_cnt[i][s[i][j] - 'a']++;
        }
    }

    // for (int i = 0; i < s.size(); i++){
    //     for (int j = 0; j < s[i].size(); j++){
    //         cout << alph_cnt[i][j] << " ";
    //     } cout << endl;
    // }

    string res = "";

    for (int i = 0; i < 26; i++){
        
        int mn = INT_MAX;

        for (int j = 0; j < n; j++){
            mn = min(mn, alph_cnt[j][i]);
        }

        if (mn != 0 || mn != INT_MAX){
            while (mn){
                // cout << " here : " << mn << endl;
                res += (i + 'a');
                mn--;
            }
        }
    }

    cout << res << endl;


    return 0;
}