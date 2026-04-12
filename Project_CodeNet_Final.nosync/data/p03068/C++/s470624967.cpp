#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; 
    cin >> n;
    string s; 
    cin >> s;
    int k;
    cin >> k;

    for(size_t i = 0; i < s.length(); i++){
        if(s[i] != s[k-1]){
            s[i] = '*';
        }
    }

    cout << s;
    return 0;
}