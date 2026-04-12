#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define endl '\n'
#define fcin ios::sync_with_stdio(false); cin.tie(nullptr);
#define inf 0x3f3f3f3f

int main(){
    fcin;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int last = -1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= last){
            ans++;  last = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}


