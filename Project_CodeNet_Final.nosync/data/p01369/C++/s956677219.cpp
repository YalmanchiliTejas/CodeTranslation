#include <iostream>
#include <vector>
#include <string>
using namespace std;


int solve(string &s) {
    string left = "qwerasdfzxcvtgb";
    int ret = 0;
    int hand = -1;
    for (size_t i = 0; i < s.length(); i++) {
        for (size_t j = 0; j < left.size(); j++) {
            if (left[j] == s[i]) {
                if (hand) {
                    ret++;
                    hand = 0;
                }
                break;
            }
            if (j+1 == left.size()) {
                if (hand != 1) {
                    hand = 1;
                    ret++;
                }
            }
        }
    }
    return ret-1;
}

int main(void){
    string s;
    vector<int> ans;
    while (1) {
        cin >> s;
        if (s == "#") break;
        ans.push_back(solve(s));
    }
    for (auto &i: ans) {
        cout << i << endl;
    }
}

