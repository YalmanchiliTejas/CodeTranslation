#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f

typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;
const int N = 1e4+5;
const ll mod = 1e9+7;
const char z='0';
string k;
ll d;
ll f[104][N], g[104][N];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> k >> d;
  reverse(k.begin(), k.end());
  int n=k.size();
  for(int res=0; res<d; res++){
    for(int p=0; p<10; p++){
      f[res][0]+=((res+p)%d)==0;
      if(p<=k[0]-z) g[res][0]+=((res+p)%d) == 0;
    }
  }

  for(int i=1; i<n; i++){
    for(int res=0; res<d; res++){
      for(int p=0; p<10; p++){
        f[res][i]+=f[(res+p)%d][i-1]%mod;
        if(p<k[i]-z) g[res][i]+=f[(res+p)%d][i-1]%mod;
        if(p==k[i]-z) g[res][i]+=g[(res+p)%d][i-1]%mod;
        f[res][i]%=mod;
        g[res][i]%=mod;
      }
    }
  }

  cout << (g[0][n-1] + mod-1)%mod << endl;
}