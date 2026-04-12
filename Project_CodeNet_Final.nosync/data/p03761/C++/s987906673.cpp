#include <bits/stdc++.h>
using namespace std;

int main() {

    map<char,int> m[50];
    int n;

    cin >> n;

    set<char> se[50];
    set<char> all_set;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        for(int k=0; k<s.size(); k++){
            m[i][s[k]]++;
            se[i].insert(s[k]);
            all_set.insert(s[k]);
        }

    }

    string ans = "";

    for(set<char>::iterator itr = all_set.begin(); itr != all_set.end(); itr++){

        int al_min = 500;

        for(int i=0; i<n; i++){

            if(se[i].find(*itr) == se[i].end()){
                al_min = 0;
                break;
            }

            al_min = min(al_min,m[i][*itr]);

        }

        for(int i=0; i<al_min; i++){

            ans.push_back(*itr);

        }

    }

    cout << ans << endl;

    return 0;
}