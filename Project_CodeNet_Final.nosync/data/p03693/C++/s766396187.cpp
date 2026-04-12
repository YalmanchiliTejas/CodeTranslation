#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    string r, g, b;
    cin >> r >> g >> b;
    string ans = r+g+b;
    int ans_int = stoi(ans);
    if(ans_int%4==0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}