#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pair;
const int Nmax = 1e5 + 5, Mod = 1e9 + 7;

string S; int i;
int main()
{
   // freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    cin.sync_with_stdio(false);

    cin >> S;
    for(i=0; i<S.size() - 1; ++i)
    if(S[i] == 'A' && S[i+1] == 'C')
    {
        cout << "Yes\n";
        return 0;
    }

    cout << "No\n";

    return 0;
}
