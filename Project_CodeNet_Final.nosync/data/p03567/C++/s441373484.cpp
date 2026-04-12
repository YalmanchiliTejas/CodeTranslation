#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <iomanip>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<class T> ostream& operator<<(ostream& stream, const vector<T> v){ stream << "["; for (int i=0; i<(int)v.size(); i++) cout << v[i] << " "; stream << "]"; return stream; }
ll fpow(ll x, ll p, ll m){ll r=1; for (;p>>=1;){ if (p&1) r=r*x%m; x=x*x%m; } return r;}
int gcd(int a, int b){ if (!b) return a; return gcd(b,a%b);}
ll gcd(ll a, ll b){ if (!b) return a; return gcd(b,a%b);}

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cr=0,i;
    cin >> s;
    for (i=0; i<(int)s.length()-1; i++)
        if (s[i]=='A' && s[i+1]=='C')
            cr=1;

    cout << (cr==1 ? "Yes" : "No\n");
	return 0;
}
