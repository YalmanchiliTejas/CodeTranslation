#include <iostream>
using namespace std;

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    string ans;
    if ( (r*100 + g * 10 + b) % 4 ==0 ){
        ans = "YES";
    }
    else ans = "NO";

    cout << ans << endl;
}