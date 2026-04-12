#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {

    string S;
    cin >> S;


    if (S[0] == S[1] and S[1] == S[2]) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}