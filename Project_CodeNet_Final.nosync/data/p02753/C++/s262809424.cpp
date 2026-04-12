#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    string s;
    cin >> s;
    unordered_set<char> cnt;
    for(char c: s)
        cnt.insert(c);
    if (cnt.size() == 1)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}

