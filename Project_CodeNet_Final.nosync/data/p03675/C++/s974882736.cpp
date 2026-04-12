// Sasageyo! Sasageyo! Shinzou wo Sasageyo !
// https://goo.gl/IwJzbx

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector< VI > VVI;

typedef long long int LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define endl '\n'
const int N = 2000000;
int x[N];
int main()
{
	fast_io;
  int n;
  cin >> n;
  VI a(n);
  for(int i=0;i<n;i++)
    cin >> a[i];
  int s, e, dir;
  s = 0, e = 0, dir = 1;
  x[0] = a[0];
  for(int i=1;i<n;i++) {
    e = (e + dir + N)%N;
    x[e] = a[i];
    swap(s, e);
    dir *= -1;
    trace(s, e, dir);
  }
  for(int i=s;i!=e;i=(i+dir+N)%N) {
    cout << x[i] << " ";
  }
  cout << x[e] << endl;
	return 0;
}