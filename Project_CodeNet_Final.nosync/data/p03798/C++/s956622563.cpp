#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;

using namespace std;        

int inputValue(){
    int a;
    cin >> a;
    return a;
};

template<typename T>
void inputArray(T* p, int a){
    rep(i, a){
        cin >> p[i];
    }
};

void inputVector(vector<int> * p, int a){
    rep(i, a){
        int input;
        cin >> input;
        p -> push_back(input);
    }
}

template <typename T>
void output(T a, int precision = 0) {
    if(precision > 0){
        cout << setprecision(precision)  << a << "\n";
    }
    else{
        cout << a << "\n";
    }
}

int N;
string s;
#define wolf 'W'
#define sheep 'S'

char reverse(char org) {
    if (org == wolf) return sheep;
    return wolf;
}


string solve(char first, char second) {
    string ans(1, first);
    ans += second;
    repd(i, 1, N+1) {
        if (s[i] == 'o') {
            if (ans[i] == wolf) {
                ans += reverse(ans[i-1]);
            } else {
                ans += ans[i-1];
            }
        } else {
            if (ans[i] == wolf) {
                ans += ans[i-1];
            } else {
                ans += reverse(ans[i-1]);
            }
        }
    }
    if (ans[0] == ans[N] && ans[1] == ans[N+1]) {
        ans.pop_back();
        ans.pop_back();
        return ans;
    } else {
        return "-1";
    }
}

int main(int argc, const char * argv[]) {
    N = inputValue();
    cin >> s;
    s += s[0];

    string ans;
    ans = solve(wolf, wolf);
    if (ans.compare("-1") != 0) {
        output(ans);
        return 0;
    }
    ans = solve(wolf, sheep);
    if (ans.compare("-1") != 0) {
        output(ans);
        return 0;
    }
    ans = solve(sheep, wolf);
    if (ans.compare("-1") != 0) {
        output(ans);
        return 0;
    }
    ans = solve(sheep, sheep);
    output(ans);
    return 0;
}
