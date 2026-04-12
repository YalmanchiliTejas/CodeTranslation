/* 
 * Project: AtCoder Beginners Contest 158 A - Station and Bus
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/03/07
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

void solve() {

    bool condition = false; 
    for (int i=0;i<3;i++) {
        if (s[i] == 'A') {
            for (int j=0;j<3;j++) {
                if (s[j] == 'B')
                    condition = true;
            }
        } else if (s[i] == 'B') {
            for (int j=0;j<3;j++) {
                if (s[j] == 'A')
                    condition = true;
            }
        }
    }
    if (condition)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {

    cin >> s;

    solve();

}
