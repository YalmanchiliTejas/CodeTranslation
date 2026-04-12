#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int num;
    num = 100*a+10*b+c;
    if(num%4==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}