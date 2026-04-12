#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i = 0; i < n; i++)

int main(void)
{
    string s;
    int n,k;
    cin >> n >> s >> k;
    REP(i, s.length()) {
        if(s[i]!=s[k-1]) s[i] = '*';
    }
    cout << s << endl;

}
