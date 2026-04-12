#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); ++i)
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;

int main(){
    string S;
    cin >> S;
    
    for (int i=0;i<2;i++){
        if (S[i]!=S[i+1]){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}