#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    int number = 100 * r + 10 * g + b;
    if (number % 4 == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}