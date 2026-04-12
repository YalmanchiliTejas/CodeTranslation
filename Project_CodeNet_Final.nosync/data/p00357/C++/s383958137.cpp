#include <bits/stdc++.h>
using namespace std;


int d[300000];
int n;

bool able(){
    int p = 0;
    for(int i = 0; i < n; i++) {
        p = max(p, i + d[i]);
        if(p == i) return false;
    }
    return true;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {cin >> d[i]; d[i] /= 10; }
    
    bool a = able();
    reverse(d, d+n);
    bool b = able();
    
    cout << (a && b ? "yes" : "no") << endl;
    
    return 0;
}
