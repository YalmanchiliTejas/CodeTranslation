#include<bits/stdc++.h>
using namespace std;
//3*3の2次元配列A
//vector<vector<int>> A(3, vector<int>(3));

void solve(){
    string S;
    cin >> S;
    if(S[0] == 'A' && S[1] == 'A' && S[2] == 'A' || S[0] == 'B' && S[1] == 'B' && S[2] == 'B'){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}