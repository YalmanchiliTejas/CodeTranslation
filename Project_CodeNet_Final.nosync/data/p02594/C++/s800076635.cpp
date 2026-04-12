#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << "=" << x << '\n'
#define debug2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << '\n'
#define forn(i, a, b) for(int i = int(a); i < int(b); i++)
#define forn_r(i, b, a) for(int i = int(b); i > int(a); i--)
#define printArray(arr, len) for(int i = 0; i < len; i++) cout << arr[i] << (i == len - 1 ? '\n' : ' ')

void test_case() {
    int n;
    cin >> n;
    
    if(n >= 30) {
    	cout << "Yes" <<'\n';
    } else {
    	cout << "No" <<'\n';
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    // int t;
    // cin >> t;

    // while(t--) {
        test_case();
    // }
    
    return 0;
}
