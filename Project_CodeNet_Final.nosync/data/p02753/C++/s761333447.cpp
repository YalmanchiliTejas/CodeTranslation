// AtCoder_158A. Station and Bus
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define FIO         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(v)      v.begin(), v.end()
#define PB          push_back
#define MP          make_pair
#define UB          upper_bound
#define LB          lower_bound
#define PI          2*acos(0.0)
#define MOD         1000000007
#define GCD(a, b)   __gcd(a, b)
#define LCM(a, b)   ((a)*(b)) / GCD(a, b)
#define INPUT       freopen("input.txt", "r", stdin);
#define OUTPUT      freopen("output.txt", "w", stdout);
#define PRINT(a)    for(auto i : a) cout << i << " "; cout << endl;
#define PRINTS(s)   for(auto i=s.begin(); i!=s.end(); i++) cout << *i << " "; cout << endl;
#define PRINTM(m)   for(auto i=m.begin(); i!=m.end(); i++) cout << i->first << " " << i->second << endl;

int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
string lowerCase = "abcdefghijklmnopqrstuvwxyz";
string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/// Graph moves
const int fxKing[] = {+1,+1,+0,-1,-1,-1,+0,+1}; /// King's move
const int fyKing[] = {+0,+1,+1,+1,+0,-1,-1,-1}; /// King's move
const int fxKnight[] = {+2,+1,-1,-2,-2,-1,+1,+2}; /// Knight's move
const int fyKnight[] = {+1,+2,+2,+1,-1,-2,-2,-1}; /// Knight's move

ll q, t, a, b, c, d, m, n, k;
ll cnt, Mn, Mx, sum, sum1, sum2, ck;
ll arr1[1000], arr2[1000];

map <ll, ll> mp1, mp2;
set <ll> st1, st2;
vector <ll> vec1, vec2;
string str1, str2, str3;

int main()
{
    FIO;
    string s;
    cin >> s;
    bool a = 0, b = 0;
    for(int i=0; i<3; i++){
        if(s[i]=='A') a = 1;
        else b = 1;
    }
    if(a&&b) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
