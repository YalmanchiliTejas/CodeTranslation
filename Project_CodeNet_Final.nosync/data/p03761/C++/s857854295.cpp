#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <math.h> // sqrt
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <iomanip> // setprecision
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int main() {
    int N;
    cin >> N;
    vector<string> data(N);
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }
    vi count(26, 0);
    int n = data[0].size();
    for (int i = 0; i < n; i++) {
        int num = data[0][i] - 'a';
        count[num]++;
    }
    for (string s : data) {
        vi ansa(26,0);
        int a = s.size();
        for (int i = 0; i < a; i++) {
            int num = s[i] - 'a';
            ansa[num]++;
        }
        for (int i = 0; i < 26; i++) {
            count[i] = min(count[i], ansa[i]);
        }
    }
    string ans = "";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < count[i]; j++) {
            char c = 'a' + i;
            ans.push_back(c);
        }
    }
    cout << ans << endl;
}
