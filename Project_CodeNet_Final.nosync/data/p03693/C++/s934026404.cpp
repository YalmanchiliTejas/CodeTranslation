#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <deque>
#include <numeric>
using namespace std;

string YorN(bool P) { if (P)return "YES"; else return "NO"; }

int main() {
    int r,g,b;
    cin >> r >> g >> b;

    cout << YorN((g*10+b)%4==0) << endl;

    return 0;

}