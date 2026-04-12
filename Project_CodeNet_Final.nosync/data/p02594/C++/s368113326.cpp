#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define RREP(i, a, b) for (int i = (int)(a)-1; i >= (int)(b); --i)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) RREP(i, n, 0)
#define ALL(r) (r).begin(), (r).end()

void Main();

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

void Main() {
    int a; cin >> a;
    cout << (a >= 30 ? "Yes" : "No") << endl;
}
