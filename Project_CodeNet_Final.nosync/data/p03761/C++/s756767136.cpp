#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str[50];
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    map<char, int> charMap[50];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < str[i].length(); ++j) {
            charMap[i][str[i][j]] = charMap[i][str[i][j]] + 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        vector<char> eraseList;
        auto itr = charMap[0].begin();
        for (; itr != charMap[0].end(); ++itr) {
            if (charMap[i][itr->first] == 0) {
                eraseList.push_back(itr->first);
            } else {
                charMap[0][itr->first] = min(charMap[0][itr->first], charMap[i][itr->first]);
            }
        }
        for (int j = 0; j < eraseList.size(); ++j) {
            charMap[0].erase(eraseList[j]);
        }
    }
    for (auto itr = charMap[0].begin(); itr != charMap[0].end(); ++itr) {
        for (int i = 0; i < itr->second; ++i) {
            cout << itr->first;
        }
    }
    cout << endl;
    return 0;
}