#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define For(i, n) for(int i = 0; i < (n); i ++)
#define Range(c) c.begin(), c.end()
#define RevRange(c) c.begin(), c.end()
#define Cin(T, x) T x; cin >> x;
#define Cins(T, n, xs) vector<T> xs(n); For(i, n) cin >> xs[i];
#define Cout(val) cout << (val) << "\n";
#define Sort(a) sort(Range(a));
#define DeSort(a) sort(RevRange(a));

using namespace std;
using ll = long long;

int main(void){
    Cin(int, d);
    Cout(800*d - 200*(d/15));
    //Cout(() ? "Yes" : "No");
    //Cout(() ? "YES" : "NO");
}