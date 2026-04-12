#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <iostream>
#include <functional>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <set>
#include <iomanip>

#define ll long long
#define mod 1000000007
#define max_limit 1000005
using namespace std;

string N;
int k;

int DP[110][4][2];

int solve(int index, int nonZero, int tightBound, vector<int> &digits) {
    if (nonZero > k) {
        return 0;
    }

    if(index == digits.size()) {
        if (nonZero == k) {
            return 1;
        }
        else {
            return 0;
        }
    }

    if(DP[index][nonZero][tightBound] != -1) {
        return DP[index][nonZero][tightBound];
    }

    int ans = 0;
    int upperLimit = (tightBound) ? digits[index] : 9;
    for(int i = 0; i <= upperLimit; i++) {
        int newNonZero = (i != 0) ? nonZero + 1 : nonZero;
        int newBound = (i == digits[index]) ? tightBound : 0;

        ans += solve(index + 1, newNonZero, newBound, digits);

    }
    DP[index][nonZero][tightBound] = ans;
    return ans;
}


int main() {

    cin>>N>>k;

    vector<int> digits;
    for(unsigned int i = 0; i < N.size(); i++) {
        digits.push_back(N[i] - '0');
    }
    memset(DP, -1, sizeof(DP));
    int ans = solve(0, 0, 1, digits);
    cout<<ans<<'\n';



    return 0;
}
