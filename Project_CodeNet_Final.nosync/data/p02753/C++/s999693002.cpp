#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int INF = 1<<30;
const long long LINF = 1LL<<60;
const long long MOD = (long long)1e9 + 7;

int main(){
    string s;
    cin >> s;
    char c = s[0];
    if(s[1] == c && s[2] == c){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}
