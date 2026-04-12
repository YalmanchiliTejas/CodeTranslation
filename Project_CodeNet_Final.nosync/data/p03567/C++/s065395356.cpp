#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
        string s;
        cin >> s;
        for (int i = 0; i < s.size() - 1; i ++) {
                if (s[i] == 'A' && s[i + 1] == 'C') return !printf("Yes\n");
        }
        printf("No\n");
        return 0;
}

