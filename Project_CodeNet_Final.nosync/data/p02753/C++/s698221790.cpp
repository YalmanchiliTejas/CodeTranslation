#include<bits/stdc++.h>
#include<string.h>
#include <math.h>
#include<iostream>
using namespace std;
typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         ld;

#define sf                  scanf
#define pf                  printf
#define srev                reverse(s.begin(),s.end())
#define sortstr             sort(s.begin(), s.end());
#define gtl(x)              getline(cin, (x))
#define gcd(a, b)           __gcd(a, b)
#define lcm(a, b)           ((a)*((b)/gcd(a,b)))
#define PI                  acos(-1)
#define Precision(a) cout << fixed << setprecision(a)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
template <typename T> T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
//scanf("%[^\n]%*c", str);
//sort(s,s+n,greater<int>());

int main()
{
    FasterIO
    string s;
    cin >> s;
    if(s[0]==s[1] && s[1]==s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
