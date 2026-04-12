#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1LL << 30;
int MOD = 1e9+7;
main(){
    string S;
    cin >> S;
    for(int i = 1;i < S.length();i++){
        if(S[i-1] == 'A' && S[i] == 'C'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}