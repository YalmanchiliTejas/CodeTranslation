#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
//long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    string S;
    cin >> S;
    char tmp = S[0];
    for(int i=1; i<S.size(); i++){
        if(tmp != S[i]){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
