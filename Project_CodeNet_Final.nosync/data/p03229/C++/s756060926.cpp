#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];
  sort(a,a+n);
  deque<int> de;
  int e=n-1;
  int s=0;

  de.pb(a[e]); e--;
  while(1){
    if(s>e) break;
    de.pb(a[s]); s++;
    if(s>e) break;
    de.push_front(a[s]); s++;
    if(s>e) break;
    de.pb(a[e]); e--;
    if(s>e) break;
    de.push_front(a[e]); e--;
    if(s>e) break;
  }
  
  ll ans=0;
  rep(i,n-1){
    //    cout << de[i] << " ";
    ans+=abs(de[i]-de[i+1]);
    //    cout << ans << endl;
  }
  //  cout << ans << endl;
  ll ans2=0;
  deque<int> de2;
  int e2=n-1;
  int s2=0;
  de2.pb(a[s2]);s2++;
  while(1){
    if(s2>e2) break;
    de2.pb(a[e2]); e2--;
    if(s2>e2) break;
    de2.push_front(a[e2]); e2--;
    if(s2>e2) break;
    de2.pb(a[s2]); s2++;
    if(s2>e2) break;
    de2.push_front(a[s2]); s2++;
    if(s2>e2) break;
  }
  
  rep(i,n-1){
    ans2+=abs(de2[i]-de2[i+1]);
  }
  cout << max(ans, ans2) << endl;
  return 0;
    

}
