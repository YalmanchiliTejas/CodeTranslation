#include <algorithm>
#include <cctype>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

const int INF = 1e9;

int main(void) {
    int n;
    cin >> n;

    vector<int> a('z' + 1, INF);
    for(int i = 0; i < n; i++){
        vector<int> b('z' + 1, 0);
        string s;
        cin >> s;
        for(char c : s){
            b[c]++;
        }
        for(int j = 'a'; j <= 'z'; j++){
            a[j] = min(a[j], b[j]);
        }
    }

    string ans;
    for(int i = 'a'; i <= 'z'; i++){
        for(int j = 0; j < a[i]; j++){
            ans.push_back((char)i);
        }
    }

    cout << ans << endl;
    return 0;
}
