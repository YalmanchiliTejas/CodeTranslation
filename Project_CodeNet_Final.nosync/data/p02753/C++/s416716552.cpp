// ========================================================================================================
// Library
// ========================================================================================================
#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;

// competitive macro
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i ,n) for (int i = (n) - 1; i >= 0; i--)
#define LL long long
#define ULL unsigned long long

void fastIOS()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
}
// ========================================================================================================
// ========================================================================================================

int main()
{
	fastIOS();

	string s; cin >> s;
    
    if(s != "AAA" && s!= "BBB")
    {
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    
    return 0;
}