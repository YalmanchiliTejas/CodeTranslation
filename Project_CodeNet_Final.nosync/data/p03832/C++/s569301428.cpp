# include <bits/stdc++.h>

# define x first
# define y second
# define mp make_pair
// everything goes according to my plan
# define pb push_back
# define sz(a) (int)(a.size())
# define vec vector
// shimkenttin kyzdary, dzyn, dzyn, dzyn...
# define y1    Y_U_NO_y1
# define left  Y_U_NO_left
# define right Y_U_NO_right

# ifdef Local
# define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
# else
# define debug(...) (__VA_ARGS__)
# define cerr if(0)cout
# endif

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;
typedef long double ld;

const int Mod = (int)1e9 + 7;
const int MX = 1073741822;
const ll MXLL = 4e18;
const int Sz = 1110111;
// a pinch of soul
inline void Read_rap () {
  ios_base :: sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}
inline void randomizer3000 () {
  unsigned int seed;
  asm ("rdtsc" : "=A"(seed));
  srand (seed);
}
void files (string problem) {
  if (fopen ((problem + ".in").c_str(),"r")) {
    freopen ((problem + ".in").c_str(),"r",stdin);
    freopen ((problem + ".out").c_str(),"w",stdout);
  }
}
void localInput(const char in[] = "s") {
  if (fopen (in, "r")) {
    freopen (in, "r", stdin);
  }
  else
    cerr << "Warning: Input file not found" << endl;
}                  
int n, a, b, c, d;
const int N = 1002;
ll G[N][N];
ll fc[N];
ll dp[N];
ll C[N][N];

ll bp (int a, int b) {
	ll res = 1;
	while (b) {
		if (b & 1)
			res = (res * a) % Mod;
		a = (a * 1ll * a) % Mod;
		b >>= 1;
	}
	return res;
}	

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n >> a >> b >> c >> d;       

  fc[0] = 1;
  for (int i = 1; i <= n; ++i)
  	fc[i] = (fc[i - 1] * 1ll * i) % Mod;
  for (int f = 1; f <= n; f++) {	
  	for (int x = 1; f * x <= n; x++) {
  		G[f][x] = fc[f*x] * bp(bp(fc[x], f), Mod-2) % Mod * bp (fc[f], Mod-2) % Mod;
  		
  	}
  }
  C[0][0] = 1;             
  for (int i = 1; i <= n; i++) {
  	C[i][0] = C[i][i] = 1;        
  	for (int j = 1; j < i; j++) {
  		C[i][j] = (C[i-1][j-1] + C[i-1][j]) % Mod;
  	}
  }	
    
  dp[0] = 1;
  for (int x = a; x <= b; x++) {
   	for (int s = n-1; s >= 0; s--) {	
			for (int f = c; f <= d && s + f * x <= n; f++) {
  			dp[s+f*x] = (dp[s + f*x] + C[n-s][f * x] * G[f][x] % Mod * dp[s] % Mod) % Mod;
  		}
  	}
  }    
  cout << dp[n];

	
  

  return 0;
}






// Coded by Z..