#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;

int dp[100000];

int main()
{
    string s;
    cin >> s;
    if(s[0] == s[1] && s[1] == s[2]){
        cout << "No";
    }else{
        cout << "Yes";
    }

}