#include <algorithm>
#include <iostream>

#define SIZE 51
#define INF  5000

int n;
std::string s;
int count[SIZE+1][26];

int main() {
    std::cin >> n;
    for (int i=0; i<n; ++i) {
        std::cin >> s;
        for (int j=0; j<s.size(); ++j) {
            ++count[i][s[j] - 'a'];
        }
    }
    for (int j=0; j<26; ++j) {
        count[SIZE][j] = INF;
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<26; ++j) {
            count[SIZE][j] = std::min(count[SIZE][j], count[i][j]);
        }
    }

    for (int i=0; i<26; ++i) {
        char x = 'a' + i;
        for (int j=0; j<count[SIZE][i]; ++j) {
            std::cout << x;
        }
    }
    std::cout << std::endl;
    return 0;
}