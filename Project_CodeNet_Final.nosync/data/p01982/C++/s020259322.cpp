#include <bits/stdc++.h>

#define var auto
#define ll long long
//#define APPLY(a, f) f(a.begin(), a.end())
#define APPLY(a, f, ...) f(a.begin(), a.end(), __VA_ARGS__)
#define FUN1(x, f) [&](auto& x){return f;}
#define FUN2(x, y, f) [&](auto& x){return f;}
using namespace std;

int main() {
    while(true){
        int n, l, r;
        cin >> n >> l >> r;
        if (n == 0) break;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int res = 0;
        for (int y = l; y <= r; y++){
            for (int i = 0; i < n; i++){
                if (y % a[i] != 0) continue;
                if (i % 2 == 0) res++;
                goto end;
            }
            if (n % 2 == 0) res++;
            end:;
        }
        cout << res << endl;
    }
}

