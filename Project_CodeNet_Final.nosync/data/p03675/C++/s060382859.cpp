#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
signed main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = n-1; i >= 0; i-=2) {
        cout << a[i] << " ";
    }
    for(int i = 0; i < n; i+=2) {
        if(n%2 == 1 && i == 0) {
            i--;;
            continue;
        }
        cout << a[i] << " ";
    }
    cout << endl;
}
