#include <bits/stdc++.h>
using namespace std;

int main(){
    string m;
    cin >> m;
    string ans = "Yes";
    
    if(m[0] == m[1]  && m[1] == m[2]){
        ans = "No";
    }
    cout << ans << endl;
    return 0;
}