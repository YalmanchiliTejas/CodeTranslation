#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// main
int main(){
    string num;
    rep(i,3){
        string rgb;
        cin >> rgb;
        num += rgb;
    }
    if(stoi(num) % 4 == 0){
        cout << "YES" << endl;
    }else
    {
        cout << "NO" << endl;
    }
    return 0;
}