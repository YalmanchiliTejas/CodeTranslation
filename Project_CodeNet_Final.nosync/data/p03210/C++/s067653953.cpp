#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    int x;
    cin >> x;
    if(x == 7 || x == 5 || x == 3){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}