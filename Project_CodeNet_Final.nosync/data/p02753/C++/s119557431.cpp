#include<bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int A = 0;
    int B = 0;
    if(s[0] == 'A') A++;
    if(s[0] == 'B') B++;
    if(s[1] == 'A') A++;
    if(s[1] == 'B') B++;
    if(s[2] == 'A') A++;
    if(s[2] == 'B') B++;
    if(A == 0 || B == 0) cout << "No";
    else cout << "Yes";
    return 0;
}
