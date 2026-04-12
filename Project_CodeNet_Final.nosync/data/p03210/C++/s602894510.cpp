#include <bits/stdc++.h>
using namespace std;
using Int = long long;
#define REP(i, n) for(int i = 0; i < n; i++)
#define DUMP(range) do{for(auto& x:range){cout<<x<<' ';}cout<<endl;}while(0)
int main()
{
    int N; cin >> N;
    cout << (N == 7 || N == 5 || N == 3 ? "YES" : "NO") << endl;
    return 0;
}