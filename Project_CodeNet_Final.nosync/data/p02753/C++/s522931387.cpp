/* You got a dream , you gotta protect it . */
/* You got a dream , you gotta protect it . */
#include <bits/stdc++.h>
#define lp(i , N) for(ll i = 0; i < ll (N) ; i++)
#define FAST ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define debug(x) cout<<" [ " << #x << " is: " << x << " ] "<<endl;
using namespace std;
typedef long long ll;
typedef long double ld;
const long double EPS = 1e-6;
const long double pi = acos(-1);
const long long MOD = 1e9 + 7;
int main(){
    FAST
    string s;
    cin >> s;
    sort(s.begin() , s.end());
    if(s[0] == s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0 ;
    }
/*
[#]=============================================================[#]
         ___    ____              ____          ___ _
        |_ _|  / ___|__ _ _ __   |  _ \  ___   |_ _| |_
         | |  | |   / _` | '_ \  | | | |/ _ \   | || __|
         | |  | |__| (_| | | | | | |_| | (_) |  | || |_
        |___|  \____\__,_|_| |_| |____/ \___/  |___|\__|
                     it's just about time

[#]=============================================================[#]
*/
