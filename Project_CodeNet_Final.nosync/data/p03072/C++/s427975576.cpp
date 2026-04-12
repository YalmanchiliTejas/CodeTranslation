#include <iostream>
using namespace std;

int n, ans;
int h[20];
bool flag;

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> h[i];

    ans = 1;
    for (int i = 1; i < n; ++i){
        flag = true;
        for (int j = 0; j < i; ++j){
            flag = (h[j] <= h[i]);
            if (!flag) break;
        }
        ans += flag;
    }

    cout << ans;
}