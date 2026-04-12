/**
    BISMILLAH
    @Author : Arham
*/
#include <bits/stdc++.h>
#define endl "\n"
#define found true
#define infinity -1
#define not_found false
#define FOR(limit) for(int i = 0; i < limit; i++)
#define __FOR(limit) for(int j = 0; j < limit; j++)
#define __FOR__(limit) for(int k = 1; k <= limit; k++)
#define hello(a) a ? "Yes" : "No"
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pf push_front
#define F first
#define S second
// getline (cin, string);
typedef long long lld;
using namespace std;
void solving_f();
int main() {
    ios_base::sync_with_stdio(not_found);
//    cin.tie(0);
//    cout.tie(0);

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    solving_f();

    return not_found;
}
void solving_f() {
    int t;
    cin >> t;
    int count = not_found;
    string s;
    if(t >= 30)
        count = found;
    s = hello(count);
    cout << s << endl;
}
