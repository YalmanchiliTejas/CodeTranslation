#include <iostream>
#include <vector>
#include <algorithm>
 
#define rep(i, n) for(int i = 0; i < (n); ++i)
 
using namespace std;

int n;
int a[200000];
int b[200000];

int main(){
    cin >> n;
    rep(i, n){
        cin >> a[i];
    }

    if(n % 2){
        rep(j, n / 2 + 1){
            b[j] = a[n - 2 * j - 1];
        }
        rep(j, n / 2){
            b[n / 2 + j + 1] = a[2 * j + 1];
        }
    }
    else{
        rep(j, n / 2){
            b[j] = a[n - 2 * j - 1];
        }
        rep(j, n / 2){
            b[n / 2 + j] = a[2 * j];
        }
    }

    rep(i, n){
        if(i){
            cout << ' ';
        }
        cout << b[i];
    }
    cout << endl;
    return 0;
}