#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int n, m;
    string result = "Yes";
    
    cin >> n >> m;
    
    if(n != m){
        result = "No";
    }
    
    cout << result << endl;
    
    return 0;
}