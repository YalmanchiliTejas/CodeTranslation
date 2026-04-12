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

string YorN(bool P) { if (P)return "Yes"; else return "No"; }

int main() {

    int N;
    cin >> N;

    cout << N*800-(N/15)*200 << endl;

    return 0;

}