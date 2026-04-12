#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    bool reverse = false;
    int n;
    cin >> n;
    int a[200050];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << a[1] << endl;
        return 0;
    }
    for(int i = n; i >= 1; i -= 2){
        cout << a[i] << " ";
    }
    for(int i = n % 2 + 1; i <= n; i += 2){
        cout << a[i];
        if(i >= (n - 1)){
            cout << endl;
        } else {
            cout << " ";
        }
    }
    return 0;
}
