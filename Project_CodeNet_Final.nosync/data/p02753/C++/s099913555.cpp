#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    string S;
    cin >> S;
    bool a = false, b = false;
    for(int i = 0; i < 3; i++){
        if(S[i] == 'A') a = true;
        else b = true;
    }
    if(a&&b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}