#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(void){
    int n;
    cin >> n;

    int h[n];
    rep(i, n)
        cin >> h[i];

    int ma = 0;
    int count = 0;
    rep(i, n){
        if(h[i] >= ma){
            count++;
            ma = h[i];
        }
    }

    cout << count << endl;
    return 0;
}
