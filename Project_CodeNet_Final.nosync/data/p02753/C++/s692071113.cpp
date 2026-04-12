#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

void solve(){
    
    string S;

    cin >> S;

    if(S == "AAA" || S == "BBB")
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(16);
    
    solve();

    return 0;
}
