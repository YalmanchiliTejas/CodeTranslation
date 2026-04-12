#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

struct aggString {
    string str;
    map<char, int> char_count;

    void init() {
        for (int i = 0; i < str.length(); ++i) {
            ++char_count[str[i]];
        }
    }

    void putString(string s) {
        map<char, int> char_count_tmp;
        for (int i = 0; i < s.length(); ++i) {
            ++char_count_tmp[s[i]];
        }
        for (auto it = char_count.begin(); it != char_count.end(); ++it) {
            if (char_count_tmp[it->first] < it->second) {
                it->second = char_count_tmp[it->first];
            }
        }
    }

    void printCharCount() {
        for (auto it = char_count.begin(); it != char_count.end(); ++it) {
            for (int i = 0; i < it->second; ++i) {
                cout << it->first;
            }
        }
        cout << endl;
    }
};

int main(void){
    // input
    int N;
    string s;
    cin >> N;
    cin >> s;
    struct aggString str = {s};
    str.init();

    for (int i = 0; i < N-1; ++i) {
        cin >> s;
        str.putString(s);
    }

    str.printCharCount();

    return 0;
}