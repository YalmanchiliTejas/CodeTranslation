#include <iostream>
using namespace std;
typedef long long ll;

int t[51] {0};
int p[51] {0};

ll thick(int i){
    if(i == 0){
        return 1;
    }
    if(t[i] != 0){
        return t[i];
    }
    else{
        return thick(i - 1) * 2 + 3;
    }
}

ll patty(int i){
    if(i == 0){
        return 1;
    }
    if(p[i] != 0){
        return p[i];
    }
    else{
        return patty(i - 1) * 2 + 1;
    }
}

ll ans(int i, ll s){
    if(i == 0){
        return 1;
    }
    if(s == 1){
        return 0;
    }
    if(2 <= s && s <= thick(i - 1) + 1){
        return ans(i - 1, s - 1);
    }
    if(s == thick(i - 1) + 2){
        return patty(i - 1) + 1;
    }
    if(thick(i - 1) + 3 <= s && s <= thick(i - 1) * 2 + 2){
        return patty(i - 1) + ans(i - 1, s - (thick(i - 1) + 2)) + 1;
    }
    else{
        return patty(i);
    }
}

int main()
{
    int n;
    cin >> n;
    ll x;
    cin >> x;
    cout << ans(n, x) << endl;
}