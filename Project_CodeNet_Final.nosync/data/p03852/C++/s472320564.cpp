#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    char c;
    cin >> c;
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }

    return 0;
}