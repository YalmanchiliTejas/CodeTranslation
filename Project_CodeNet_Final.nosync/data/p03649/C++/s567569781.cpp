#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pii pair<int,int>
#define sz(x) (int)x.size()
#define piii pair<pii,pii>
#define precise cout<<fixed<<setprecision(10)
#define st first
#define nd second
#define ins insert
#define vi vector<int>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int MAX=55;
int a[MAX];
int32_t main()
{
  BOOST;
  int ans=0;
  int n;
  cin>>n;
  for (int i=0;i<n;i++)cin>>a[i];
  while (true){
  	int pos=max_element(a,a+n)-a;
  	if (a[pos]<n)break;
  	for (int i=0;i<n;i++) if (i!=pos)a[i]+=a[pos]/n;
  	ans+=a[pos]/n;
  	a[pos]%=n;
  }
  cout<<ans;
  return 0;
}
