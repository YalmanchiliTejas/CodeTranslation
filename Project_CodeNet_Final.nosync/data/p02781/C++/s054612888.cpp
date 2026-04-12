// NK
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define psf push_front
#define pof pop_front
#define mkp make_pair
#define all(x) x.begin(), x.end()

int main(){
  //#ifndef ONLINE_JUDGE
  //freopen("ia.txt", "r", stdin);
  //freopen("oa.txt", "w", stdout);
  //#else
  ios::sync_with_stdio(false), cin.tie(nullptr);
  //#endif

  string a;
  int k;
  cin>>a>>k;
  int n=a.size();

  ll ans=0;
  if (k==1){
    for (int i=0; i<n; i++){
      if (!i) ans+=-'0' + a[i];
      else ans+=9;
    }
    cout<<ans<<'\n';
    return 0;
  }
  if (k==2){
    for (int i=1; i<n-1; i++){
      for (int j=i+1; j<n; j++){
        ans+=9*9;
      }
    }

    bool sw=0;
    for (int i=1; i<n; i++){
      if (!sw) ans+=a[i]-'0';
      else ans+=9;
      if (a[i]!='0') sw=1;
    }

    ll curr=a[0]-'0'-1;
    for (int i=1; i<n; i++){
      ans+=curr*9;
    }
    cout<<ans<<'\n';
    return 0;
  }
  for (int i=1; i<n-2; i++){
    for (int j=i+1; j<n-1; j++){
      for (int jj=j+1; jj<n; jj++){
        ans+=9*9*9;
      }
    }
  }

  ll curr=a[0] - '0' -1;
  for (int j=1; j<n-1; j++){
    for (int jj=j+1; jj<n; jj++){
      ans+=curr*9*9;
    }
  }

  int i;
  for (i=1; i<n-1; i++){
    if (a[i]!='0'){
      for (int j=i+1; j<n-1; j++)
        for (int jj=j+1; jj<n; jj++)
          ans+=9*9;

      bool sw=0;
      for (int j=i+1; j<n; j++){
        if (!sw) ans+=a[j]-'0';
        else ans+=9;
        if (a[j]!='0') sw=1;
      }

      curr=a[i]-'0'-1;
      for (int j=i+1; j<n; j++){
        ans+=curr*9;
      }
      break;
    }
  }
  cout<<ans<<'\n';

  return 0;
}
