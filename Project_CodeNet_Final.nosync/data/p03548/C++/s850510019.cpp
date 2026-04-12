#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
#define PI 3.141592653589793

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    for(int i = 1; ; i++){
        if(i*y + (i+1)*z > x){
            cout << i - 1 << endl;
            return 0;
        }
    }
}
