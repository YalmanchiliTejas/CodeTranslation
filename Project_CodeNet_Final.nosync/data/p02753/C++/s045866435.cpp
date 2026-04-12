#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    char s[3];
    cin >> s;
    if (s[0]!=s[1] or s[1]!=s[2] or s[2]!= s[0]){
        cout << "Yes" << endl;

    }
    else{
        cout << "No" << endl;
    }

    return 0;
}