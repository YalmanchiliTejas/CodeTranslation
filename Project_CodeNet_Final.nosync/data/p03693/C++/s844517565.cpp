#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define pb push_back
#define sz(s) (int)s.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)

const int N=(int)1e5+7;
const long long inf = (long long)1e16 + 7;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if((a*100+b*10+c)%4==0) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}