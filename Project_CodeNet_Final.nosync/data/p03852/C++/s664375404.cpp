#include <bits/stdc++.h>
using namespace std;

#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define fr(i, a, b) for(int i = a ; i < b ; i++)
#define frr(i, a, b) for(int i = a ; i >= b ; i--)
#define tr(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define trr(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define its(x) static_cast< ostringstream & >( ( ostringstream() << dec << x ) ).str() // int to string
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define deb(x) cout << #x" = " << x << '\n'
#define has(cont, x) ((cont).find((x)) != (cont).end())
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;



int main() {
//    freopen("input.in", "r", stdin);
	char c;
	scanf("%c", &c);
	puts((c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') ? "vowel" : "consonant");
	return 0;
}