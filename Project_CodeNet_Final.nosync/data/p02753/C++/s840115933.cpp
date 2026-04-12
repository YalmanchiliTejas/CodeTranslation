#include<bits/stdc++.h>

using namespace std;


void _accepcted_by_one_hit_()
{
    #ifdef NTMA
        freopen("abc.inp", "r", stdin);
        freopen("abc.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

int main()
{	
	_accepcted_by_one_hit_();
    string s; cin >> s;
    if (s == "AAA" || s == "BBB") cout << "No\n";
    else cout << "Yes";
    
}