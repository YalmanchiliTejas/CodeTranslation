#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define pf push_front 
#define mp make_pair
#define fr first
#define sc second
#define Rep(i,n) for(int i=0;i<(n);i++)
#define All(v) v.begin(),v.end()
typedef pair<int, int> Pii; typedef pair<int, Pii> Pip;
const int INF = 1107110711071107;


main()
{
  int a, b, c;
  cin >> a >> b >> c;
  if( (a * 100 + b * 10 + c) % 4 == 0 ) cout << "YES" << endl;
  else cout << "NO" << endl;
}
