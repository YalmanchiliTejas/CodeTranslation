#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ll long long unsigned
#define pii pair<int,int>
#define tii tuple <int,int,int>
#define N 1000005
#define mod 2000003
#define X first
#define Y second
#define eps 0.0000000001
#define all(x) x.begin(),x.end()
#define tot(x) x+1,x+n+1
using namespace std;
char c;
int main()
{
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin>>c;
    if(strchr("aeiou",c))
        cout<<"vowel";
    else
        cout<<"consonant";
    return 0;
}


