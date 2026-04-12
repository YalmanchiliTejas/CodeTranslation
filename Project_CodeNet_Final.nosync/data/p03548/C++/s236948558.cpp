#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll mod7 = 1000000007;

#define eb(x) emplace_back(x)
#define ef(x) emplace_front(x)
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define ob(x) pop_back(x)
#define of(x) pop_front(x)
#define mp(a, b) make_pair(a, b)

#define power(x, p) round(pow(x, (double)p))
#define all(x) x.begin(), x.end()
#define sortAs(x) sort(all(x));
#define sortDes(x) sort(all(x), std::greater<ll>());

#define fori(x) for (ll i = 0; i < x; i++)
#define forj(x) for (ll j = 0; j < x; j++)
#define fork(x) for (ll k = 0; k < x; k++)

#define ret(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define rep(u, s, x) for (ll u = s; u <= x; u++)
#define rem(u, x, s) for (ll u = s; u >= x; u--)

#define RET(t) cout << t << endl; return 0;
#define RETIF(i, t) if (i) { cout << t << endl; return 0; }
#define BREAKIF(i, t) if (i) { cout << t << endl; break; }
#define CONTIF(i, t) if (i) { cout << t << endl; continue; }

#define NEWLINE cout << endl;
#define DBG(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); cout << endl; }

vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cout << it -> substr((*it)[0] == ' ', it -> length()) << ": " << a << " ";
	err(++it, args...);
}

#define DBGARRAY(x, s) cout << #x << ": "; for (int z = 0; z < s; z++) cout << x[z] << " "; cout << endl;
#define DBGVECTOR(x) cout << #x << ": "; for (ll z = 0; z < x.size(); z++) cout << x[z] << " "; cout << endl;
#define DBGVECTORPAR(x, p) cout << #x << ": "; for (ll z = 0; z < x.size(); z++) cout << x[z].p << " "; cout << endl;
#define DBGMAP(x) cout << #x << ":" << endl; for (auto z = x.begin(); z != x.end(); z++) { cout << z->first << ": " << z->second << endl; }
#define DBGSET(x) cout << #x << ":" << endl; for (auto z = x.begin(); z != x.end(); z++) { cout << *z << endl;}

bool isPrime(long long a) { if (a <= 1) return 0; for(long long i = 2; i * i <= a; i++) { if(a % i == 0) return 0; } return 1; }

ll lcm(ll a, ll b) { return __gcd(a, b) ? (a / __gcd(a, b) * b) : 0; }

template<typename T>
ll biggest(T x) {ll b_i = 0; fori(x.size()) {if (x[b_i] < x[i]) {b_i = i;} } return b_i;}
template<typename T>
ll smallest(T x) {ll s_i = 0; fori(x.size()) {if (x[s_i] > x[i]) {s_i = i;} } return s_i;}

template<typename T>
string tostring(T num) { stringstream convert; convert << num; return convert.str(); }
template<typename T>
ll tonumber(T stringNum) { ll a; stringstream convert; convert << stringNum; convert >> a; return a; }


ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
char C1, C2, C3, C4;
string S1, S2, S3, S4;
vl V1, V2, V3, V4;
bool B1, B2;

int main()
{
    std::ios_base::sync_with_stdio(0); cin.tie(0); cin.clear();

    cin >> A >> B >> C;

    int i = 0;

    while (B * i + (i + 1) * C <= A)
        i++;

    cout << i - 1;
}

