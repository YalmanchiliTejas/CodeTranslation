#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
#define ALL(obj) (obj).begin(),(obj).end()

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    int sum=g*10+b;
    if(sum%4){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}
