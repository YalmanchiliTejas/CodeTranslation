/* 
 * Project: AtCoder Beginners Contest 064 A - RGB Cards
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/04/04
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int r;
int g;
int b;

void solve() {

int number = 0;
int rem = 0;

number = 100*r + 10*g + b;
rem = number & 3;

    if (rem == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {

    cin >> r >> g >> b;

    solve();

}
