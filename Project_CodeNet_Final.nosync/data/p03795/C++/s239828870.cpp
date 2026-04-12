#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <cmath>
#include <bitset>
#define REP(i,n) for(int i=0;i<n;i++)
using Int = long long;
using namespace std;
int main()
{
    int N; cin >> N;
    cout << N * 800 - (N / 15) * 200 << endl;
    return 0;
}