//
//  main.cpp
//  procon
//
//  Created by ???????????? on 2015/05/21.
//  Copyright (c) 2015??´ y. inoue. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    while (true) {
        string s;
        cin >> s;
        int hand[26] = {0, 0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1, 1, 1, 1,
            0, 0, 0, 0,
            1, 0, 0, 0, 1, 0};

        if (s == "#") {
            break;
        }

        int ans = 0;
        for (int i = 1; i < s.length(); i++) {
            if (hand[s[i-1] - 97] != hand[s[i] - 97]) {
                ans++;
            }
        }

        cout << ans << "\n";
    }
}