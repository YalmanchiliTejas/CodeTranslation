#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wmissing-declarations"

#define FINAL_OUT(x) {cout << (x) << '\n'; exit(0);}

#define SHOW(x) std::cout << #x << " = " << x << std::endl;

inline int safe_mul(const int x, const int y) __attribute__ ((warn_unused_result));

int main()
{
//    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    int a = 0;
    for(int i = 0; i < 3; ++i)
    {
        a *= 10;
        int y;
        cin >> y;
        a += y;
    }
    cout << (a % 4 ? "NO" : "YES") << endl;

}
