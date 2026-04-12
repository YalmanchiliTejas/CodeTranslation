//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

//Some constants don't work
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
#ifndef INT_MIN
#define INT_MIN -2147483648
#endif
//short hand tricks
typedef long long ll;

using namespace std;

int main(int argc, char * argv[]) {
    ios_base::sync_with_stdio(false);
    int x;
    cin >> x;
    if(x>=30) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
