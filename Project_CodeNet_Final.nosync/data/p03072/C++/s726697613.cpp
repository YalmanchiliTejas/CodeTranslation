#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int a;
    int lf = 0, c = 0;
    for(int i = 0; i < n; i++){
    cin >> a;
    if(a >= lf){
        c++;
        lf = a;
    }
    }
    cout << c;
    
    return 0;
}