#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

int main(void) {
    int H,W;cin>>H>>W;
    vector<string> s;
    for (int i = 0; i < H; i++) {
        string tmp;cin>>tmp;
        bool hit = false;
        for (int j = 0; j < W; j++) {
            if (tmp[j] == '#') hit = true;
        }
        if (hit) s.push_back(tmp);
    }
    int len = s.size();
    set<int> trim_index;
    for (int i = 0; i < W; i++) {
        bool hit = false;
        for (int j = 0; j < len; j++) {
            if (s.at(j)[i] == '#') hit = true;
        }
        if (!hit) trim_index.insert(i);
    }
    // output
    for (int j = 0; j < len; j++) {
        for (int i = 0; i < W; i++) {
            if (trim_index.find(i) == trim_index.end()) {
                printf("%c", s.at(j)[i]);
            }
        }
        cout << endl;
    }
    return 0;
}