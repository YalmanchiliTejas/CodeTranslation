#include <bits/stdc++.h>
#define Phuong_ ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define mp make_pair

/// easy access -------------
using namespace std;
using ll = long long;
using ld = long double;
typedef pair<int,int> pii;
///-------------------------

/// problem's variable---------------



///--------------------------


int main()
{
    Phuong_;
    string s;
    cin >> s;
    int a=0;
    int b=0;
    for(int i=0;i<3; ++i)
    {
        if (s[i]=='A') a++; else b++;
    }
    if (a==2 || b==2) cout << "Yes"; else cout << "No";
    return 0;
}

