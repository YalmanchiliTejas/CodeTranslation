#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;


int main() {
    int a;
    cin >> a;
    int paid = a*800;
    int ret = (a/15)*200;
    cout << paid - ret;
    cout << endl;
}