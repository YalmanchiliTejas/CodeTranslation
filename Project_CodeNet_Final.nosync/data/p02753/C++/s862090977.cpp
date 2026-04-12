#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const string YES = "Yes";
const string NO = "No";

void solve(std::string S)
{
    if (S[0] == S[1] && S[1] == S[2])
        cout << NO << endl;
    else
        cout << YES << endl;
}

int main()
{
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
