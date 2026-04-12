#include <iostream>
#include <cstring>
using namespace std;
const int M = 2e5 + 10;
int a[M] , b[M];
int main() {
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    int flag = 0;
    int l = 1 , r = n;
    for(int i = n ; i >= 1 ; i--) {
        if(flag == 0) {
            b[l] = a[i];
            l++;
            flag = 1;
            continue;
        }
        else {
            b[r] = a[i];
            r--;
            flag = 0;
        }
    }
    for(int i = 1 ; i <= n ; i++) cout << b[i] << ' ';
    cout << endl;
    return 0;
}