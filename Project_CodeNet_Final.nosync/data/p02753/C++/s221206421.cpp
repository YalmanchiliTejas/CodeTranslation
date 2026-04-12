#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define FOR(x,y) for(ll x=0; x < (ll)y; x++)



int main() {

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if(s[0] != s[2]){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}
