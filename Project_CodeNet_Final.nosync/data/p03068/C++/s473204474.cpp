/*
    Author - FireDrake99
*/
#include<bits/stdc++.h>
using namespace std;

//------------Constants-----------------
#define ll long long int
//------------Variables-----------------
int n,k;
string s;
//------------Functions-----------------

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//------------Input---------------------
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    cin >> s;
    cin >> k;
//------------Work----------------------
    char c=s[k-1];
    for (int i=0; i<n; i++)
        if (s[i]!=c) s[i]='*';
    cout << s;
}
