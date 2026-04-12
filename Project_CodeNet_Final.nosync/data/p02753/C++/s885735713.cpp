///mAAria...
#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define ld long double
#define ff first
#define ss second
#define pii pair<int,int>
#define pi 3.1415926535897932384626433832
#define mod 1000000007
#define inf 1000000000
#define pr1(a) cout << a << endl
#define pr2(a,b)cout << a <<  " " <<b<< endl
#define pr3(a,b,c) cout << a <<" " << b << " " << c << endl

const long double PI = acos(-1);

int powm(int a, int b) {
    int res=1;
    while(b) {
        if(b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

int gcd(int a, int b){
    if(b==0)return a;
    gcd(b,a%b);
}


void solve(){
    string s;
    cin >> s;
    int a =0, b= 0;
    for(int i = 0;i<3;i++){
        if(s[i]=='A')a++;
        else b++;
    }

    if(a&&b){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

 
} 

signed main() 
{   
    IOS;
    int t = 1;
    //cin >> t;

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
} 

 
