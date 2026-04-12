#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int h, w;
    cin >> h >> w;
    vector<string> vec;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        if (count(s.begin(), s.end(), '.') == s.size()) continue;
        vec.push_back(s);
    }


    for (int j = 0; j < w; j++) {
        bool flag = true;
        for (int i = 0; i < vec.size(); i++) {
            if (vec.at(i).at(j) == '#') flag = false;
        }

        if (flag) {
            for (int i = 0; i < vec.size(); i++) {
                vec.at(i).erase(vec.at(i).begin()+j);
            }
            w--;
            j--;
        }
    }


    for (auto elem : vec) {
        cout << elem << endl;
    }

    return 0;
}
