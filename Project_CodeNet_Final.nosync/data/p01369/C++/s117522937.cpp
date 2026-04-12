#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using hset = unordered_set<T>;
template<class Key, class T> using hmap = unordered_map<Key, T>;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

hset<char> lKey = {
    'q', 'w', 'e', 'r', 't',
    'a', 's', 'd', 'f', 'g',
    'z', 'x', 'c', 'v', 'b',
};

int main() {
    string s;
    while (cin >> s) {
        if (s == "#") break;
        bool flg = lKey.find(s[0]) != lKey.end();
        int cnt = 0;
        for (char c : s) {
            if (flg != (lKey.find(c) != lKey.end())) cnt++;
            flg = (lKey.find(c) != lKey.end());
        }
        cout << cnt << endl;
    }

    return 0;
}