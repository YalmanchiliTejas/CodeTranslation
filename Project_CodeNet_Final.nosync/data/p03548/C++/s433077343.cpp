  #include <bits/stdc++.h>
  #define Mod 1000000007
  #define INF 9e8
  #define INFL 9e18
  #define EPS 1e-9
  #define pb push_back
  #define mp make_pair
  #define SET(a) memset(a,-1,sizeof(a))
  #define CLR(a) memset(a,0,sizeof(a))
  #define CPY(a,b) memcpy(a,b,sizeof(a))
  #define N 200005
  #define fs first
  #define sc second 
  #define UNIVISITED 0
  #define EXPLORED 1
  #define VISITED 2
  using namespace std;
  typedef  long long int ll;
  typedef pair<ll,ll> ii;
  typedef vector <ii> vii;
  typedef vector <ll> vi;

  ll arr[N],pos[N];

  int main()
  {
  
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll x,y,z;
  cin>>x>>y>>z;
  x-=z;
 ll ans=x/(y+z);
  cout<<ans<<endl;



  return 0;


  } 