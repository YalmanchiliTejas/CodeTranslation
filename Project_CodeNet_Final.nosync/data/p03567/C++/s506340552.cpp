#include "bits/stdc++.h"
using namespace std;
#define fi first
#define se second
#define ll long long
#define dbg(v) cerr<<#v<<" = "<<v<<'\n'
#define vi vector<int>
#define vl vector <ll>
#define pii pair<int,int>
#define mp make_pair
#define db long double
#define pb push_back
#define all(s) s.begin(),s.end()
int main(void)
{
    string str;
    cin>>str;
    for (int i = 0;i + 1 < str.length();++i)
        if (str[i] == 'A' && str[i + 1] == 'C')
            return puts("Yes") * 0;
    puts("No");
    return 0;
}
