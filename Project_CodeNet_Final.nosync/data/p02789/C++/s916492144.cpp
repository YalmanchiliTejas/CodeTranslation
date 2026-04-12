#include <iostream>
#include <string>

using namespace std;

int N, M;
string ans;

void resolve()
{
    cin >> N >> M;

    ans = (M == N) ? "Yes" : "No";
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    resolve();
    return 0;
}
