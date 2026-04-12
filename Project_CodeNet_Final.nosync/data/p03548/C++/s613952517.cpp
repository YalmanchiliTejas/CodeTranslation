#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
#include <bits/stdc++.h>
#include <limits>

#define MOD 1000000007

using namespace std;

int main(void){
    // Your code here!
    long long x, y, z;
    
    cin >> x >> y >> z;
    
    cout << (x - z) / (y + z) << endl;
    
    return 0;
}