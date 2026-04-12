#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
//int a[200010];
int b[200010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        if(n % 2 == 0){
            if(i % 2 == 0){
                b[n / 2 + i / 2] = a;
            }
            else {
                b[n / 2 - i / 2 - 1] = a;
            }
        }
        else {
            if(i % 2 == 0){
                b[n / 2 - i / 2] = a;
            }
            else {
                b[n / 2 + i / 2 + 1] = a;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(i != 0){
            cout << " ";
        }
        cout << b[i];
    }
    cout << endl;

    return 0;
}