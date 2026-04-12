#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip> //fixed << setprecision(10)

using namespace std;

#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

typedef long long ll;
typedef vector<int> vi;

int main(){
    char s[3];
    rep(i, 3){
        cin >> s[i];
    }
    if(s[0] == s[1]){
        if(s[0] == s[2]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}