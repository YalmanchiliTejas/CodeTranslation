//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <complex>
#include <regex>

using namespace std;

#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}


int main() {

    int H, W;
    cin >> H >> W;

    vector <string> a(H);
    for (int i = 0; i < H; i++)cin >> a[i];

    vector <vector<bool>> flags(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++) {
        bool flag = true;
        for (int j = 0; j < W; j++) if (a[i][j] == '#')flag = false;
        if (flag) for (int j = 0; j < W; j++) flags[i][j] = true;
    }
    for (int i = 0; i < W; i++) {
        bool flag = true;
        for (int j = 0; j < H; j++) if (a[j][i] == '#') flag = false;
        if (flag)for (int j = 0; j < H; j++) flags[j][i] = true;
    }
//
//    for (int i = 0; i < H; i++) SHOW_VECTOR(flags[i]);

    vector <string> ans;
    for (int i = 0; i < H; i++) {
        string str = "";
        for (int j = 0; j < W; j++) if (!flags[i][j]) str += a[i][j];
        if (str.size()) ans.push_back(str);
    }

    for (auto x: ans)cout << x << endl;

}













































