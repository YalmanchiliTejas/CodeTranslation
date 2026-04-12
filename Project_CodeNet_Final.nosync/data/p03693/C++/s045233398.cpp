#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int num=a*100+b*10+c;
    string ans;
    
    if (num%4 == 0) {
        ans = "YES";
    } else ans = "NO";
    
    cout << ans << endl;
    return 0;
    
}
