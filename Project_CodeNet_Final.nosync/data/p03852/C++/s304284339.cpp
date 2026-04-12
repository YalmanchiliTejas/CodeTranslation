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
    Cin(string, a);
    Cin(int, b);
    Cin(int, c);
    Cin(int, d);
    //Cout();
    //Cout(() ? "Yes" : "No");
    Cout((a == "a" || a == "i" || a == "u" || a == "e" || a == "o") ? "vowel" : "consonant");
}