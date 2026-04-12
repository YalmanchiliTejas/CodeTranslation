#include <iostream>
#include <iomanip>
#include <string>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n, k;
    string s;
    cin >> n >> s >> k;
    repi(i,n,0){
        if(s[i] != s[k-1])cout << '*';
        else cout << s[i];
    }
    cout << endl;
    return 0;
}