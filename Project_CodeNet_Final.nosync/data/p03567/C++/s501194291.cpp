#include <iostream>

using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    for(ll i = 0; i < s.size() - 1; ++i){
        if(s.substr(i, 2) == "AC"){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
