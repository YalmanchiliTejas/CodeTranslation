#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    char c;
    vector<char> vow={'a','e','i','o','u'};
    cin>>c;
    if (find(vow.begin(),vow.end(),c)!=vow.end())
        cout<<"vowel\n";
    else
        cout<<"consonant\n";
}