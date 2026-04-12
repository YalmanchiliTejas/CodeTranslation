#include <bits/stdc++.h>

using namespace std;
#define mp(a,b) make_pair(a,b)
#define fast cin.tie(0);cout.tie(0);std::ios_base::sync_with_stdio(0);
#define fuf -1;
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)
#define mid3(a,b,c) a+b+c-max3(a,b,c)-min3(a,b,c)
#define nullptr NULL
//typedef long long int ll;
#define int long long

const double EPS = 0.0000000001;
const int mod1 = 998244353;
const int mod2 = 1000000007;
const int mod3 = 1000000009;
const int inf = 1000000000000000000;
using namespace std;

signed main(){
    int n;
    cin >> n;
    int mass[n];
    for(int i = 0;i<n;i++) cin >> mass[i];
    int maxi = -1;
    int c = 0;
    for(int i = 0;i<n;i++){
        if(mass[i] >= maxi){
            c++;
        }
        maxi = max(maxi,mass[i]);
    }
    cout << c;
}
