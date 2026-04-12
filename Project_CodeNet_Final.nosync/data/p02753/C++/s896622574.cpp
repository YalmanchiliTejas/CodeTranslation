#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    string s;
    cin >> s;
    int i;
    for(i=0;i<s.size()-1;i++){
        //cout << s[i] << " " << s[i+1] << endl;
        if(s[i] != s[i+1]){cout << "Yes" << endl;return 0;}
    }
    cout << "No" << endl;

    return 0;
}
