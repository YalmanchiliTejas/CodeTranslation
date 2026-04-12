#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
#include <unordered_map> 
#include <map> 
#include <numeric>
#include <limits>
#include <utility>
#include <queue>
#include <random>
#include <bitset>
#include <memory>
using namespace std;
typedef long long LL;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    vector<string> ans;
    
    bool t = true;

    for (int i = 0; i < h; i++) {
        cin >> a[i];
    }
    string s = "";
    for (int i = 0; i < w; i++) {
        s += ".";
    }
    /*for (int i = 0; i < a.size(); i++) {
        if (a[i] == s) {
            a.erase(a.begin() + i);
            i = 0;
        }
    }*/

    for (int i = 0; i < h; i++) {
        if (a[i] == s) {
            continue;
        }
        ans.push_back(a[i]);
    }
    string ss = "";
    vector<string> ans2(ans.size(), "");
    for (int i = 0; i < ans.size(); i++) {
        ss += '.';
    }

    for (int i = 0; i < ans[0].size(); i++) {
        string e = "";
        for (int j = 0; j < ans.size(); j++) {
            e += ans[j][i];
        }
        if (e != ss) {
            for (int k = 0; k < ans.size(); k++) {
                ans2[k] += e[k];
            }
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans2[i] << endl;
    }

    return 0;
}