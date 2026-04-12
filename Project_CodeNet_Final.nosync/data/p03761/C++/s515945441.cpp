#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    string str;
    vector<int> Min(26, 0);
    vector<char> vec(26);
    vec = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
           'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> str;
        map<char, int> m;
        for (int j = 0; j < str.size(); j++) {
            //
            m[str.at(j)]++;
        }

        if (i == 0) {
            int tmp = 0;
            for (auto itr : m) {
                for (int j = tmp; j < 26; j++) {
                    if (vec.at(j) == itr.first) {
                        Min.at(j) = itr.second;
                        // Min.at(j) = min(Min.at(j), itr.second);
                        tmp = j + 1;
                        // cout <<  tmp << endl;
                        break;
                    } else {
                        Min.at(j) = 0;
                    }
                }
            }
            for (int j = tmp; j < 26; j++) { Min.at(j) = 0; }
        } else {
            int tmp = 0;
            for (auto itr : m) {
                for (int j = tmp; j < 26; j++) {
                    if (vec.at(j) == itr.first) {
                        Min.at(j) = min(Min.at(j), itr.second);
                        tmp = j + 1;
                        // cout << tmp << endl;
                        break;
                    } else {
                        Min.at(j) = 0;
                    }
                }
            }
            for (int j = tmp; j < 26; j++) { Min.at(j) = 0; }
        }
    }
    string kekka;
    for (int i = 0; i < 26; i++) {
        if (Min.at(i) > 0) {
            for (int j = 0; j < Min.at(i); j++) { kekka += vec.at(i); }
        }
    }

    cout << kekka;
    //
}
