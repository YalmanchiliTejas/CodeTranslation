#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
    int n;
    string s;
    cin >> s;
    if (s[1] == 'A' && (s[0] == 'B' || s[2] == 'B')) cout << "Yes" << endl;
    else if (s[1] == 'B' && (s[0] == 'A' || s[2] == 'A')) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
