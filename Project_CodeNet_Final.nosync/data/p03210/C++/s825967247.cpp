#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int x;
    cin >> x;
    
    string s = "NO";
    if(x == 3 || x == 5 || x == 7) s = "YES";
    
    cout << s << endl;
    return 0;
}