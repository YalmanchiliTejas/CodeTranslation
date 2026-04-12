#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back

typedef vector<int> vint;
typedef long long ll;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &ref:a){
        cin >> ref;
    }
    int l, ans;
    l = a[0];
    ans = 0;
    for(auto i:a){
        if(i >= l){
            ans++;
            l = i;
        }
    }

    cout << ans << endl;
}
