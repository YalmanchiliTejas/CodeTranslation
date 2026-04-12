/* 
 * Author: pawanmsr
 */

/*
 * Run in Mac using the following command:
 * g++ -std=c++14 <cpp_filename>
 * A binary will be generated. Then run:
 * ./a.out
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <fstream>
#include <cstring>
#include <unordered_map>

// #include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

// Macro //
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

// Global //
int n, m;

// Functions //


// Main //
int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // // freopen("output.txt", "w", stdout);
    // #else
    // // online submission
    // #endif
    
    /* code */

    cin >> n >> m;
    if (n==m) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}