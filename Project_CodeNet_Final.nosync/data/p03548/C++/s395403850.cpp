#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int main(){
    int x, y, z;
    cin >> x >> y >> z;
    for(int i = 1;; i++){
        if(i*y + z*(i+1) > x){
            cout << i - 1 << endl;
            return 0;
        }
    }
}
