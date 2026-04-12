#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << '>' << #x << ':' << x << endl;
#define loop0(i,n) for(int i=0; i<(n); i++)
#define loop1(i,n) for(int i=1; i<=(n); i++)
#define fori(a,b,i) for(int i=(a); i<=(b); i++)
#define ford(a,b,i) for(int i=(a); i>=(b); i--)
#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ign cin.ignore(numeric_limits<streamsize>::max(),'\n')

#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl "\n"
#define fir first
#define sec second
#define pb push_back
#define mp make_pair

typedef long long int ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<vector<int>> MAT;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MII;
typedef map<int,int> MCI;
typedef unordered_map<int,int> UMII;
typedef unordered_map<ll,ll> UMLL;
typedef unordered_map<char,int> UMCI;
typedef set<int> SI;
typedef unordered_set<int> USI;

// Display Map
//~for (auto const& pair: m) {
//~std::cout << "{" << pair.first << ": " << pair.second << "}\n";
//~}

// Extract word(w) from sentence(s)
//~stringstream str(s);
//~string w;
//~while(str >> w){
//~// w is your word
//~}

//Memset Syntax
// memset(array, value,sizeof(array)) val is 0,-1 or bool only

// To get accurate precision
//~cout.precision(20);

// Concatinate Vectors
//~

int main() {
    fast_io;
	int x;
	cin >> x;
	if(x >= 30) cout << "Yes" << endl;
	else cout << "No" << endl;
	
}
