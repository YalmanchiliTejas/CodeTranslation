#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define go(i, a, n) for (ll i = a; i < (ll)n; i++)
#define gor(i, a, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define gos(i, a, n, step) for (ll i = a; i < (ll)n; i += step)
#define show(a) cout << a << '\n'
#define show2(a, b) cout << a << " " << b << '\n'
#define show3(a, b, c) cout << a << " " << b << " " << c << '\n'
#define show4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << '\n'
#define ull unsigned long long
#define ld long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define mod 1000000007
#define mem(a, k) memset(a, k, sizeof(a))
#define answer(z, k) cout << "Case #" << z << ": " << k << endl;
auto t1 = chrono::high_resolution_clock::now();
class student
{
public:
    string name, rno;
    float marks;
    ll index;
};
bool cmp(student a, student b)
{
    if (a.marks == b.marks)
        return a.index < b.index;
    return a.marks < b.marks;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    if (n >= 30)
        show("Yes");
    else
        show("No");
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    clog << "Time taken = " << duration * 1.0 / 1000 << " seconds" << endl;
    return 0;
}