#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    string s;
    cin >> s;
    int cnt = 1;
    repi(i,s.size(),1){
        if(s[0] == s[i])cnt++;        
    }
    cout << (cnt == 3 ? "No":"Yes") << endl;
    return 0;
}