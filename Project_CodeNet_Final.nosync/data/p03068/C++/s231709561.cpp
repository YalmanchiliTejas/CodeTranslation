#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void){
    int n,k;
    string s;
    cin >> n >> s >> k;
    char s1 = s[k-1];
    for (int i = 0; i < n; ++i) {
        if (s[i] != s1) s[i] = '*';
    } 
    cout << s << endl;
    return 0;
}