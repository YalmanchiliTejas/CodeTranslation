#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for (int i=a; i<b; ++i)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int A=0, B=0;
    loop(i,0,s.length()){
        if (s[i]=='A') A=1;
        if (s[i]=='B') B=1;
    }
    if (A&&B) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}