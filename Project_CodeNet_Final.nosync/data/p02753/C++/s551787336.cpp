/*
 *
 * Author: r3gz3n
 * 
 * 3b 13 12 9 56 4e
 * 6 56 a a 5f f
 * 6 56 47 18 56 d
 * 13 46 14 1f 13 27
 * 52 52 a 5a 47 1
 * 1d 13 b 1b 49 17
 *
 */


#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;


#define endl '\n'


class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        string s;
        in >> s;
        if (s[0] == s[1] and s[1] == s[2]) out << "No" << endl;
        else out << "Yes" << endl;
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}


#include <fstream>
#include <iostream>


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}


