#include <bits/stdc++.h>
using namespace std;
const int N=200010,Mod=998244353;
const double pi=acos(-1.0);
typedef long long int ll;
typedef pair<int,int> pii;
int n,a[N];
multiset<int> last;
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    auto it=last.lower_bound(a[i]);
    if(it==last.begin()) last.insert(a[i]);
    else
    {
      it--;
      last.erase(it);
      last.insert(a[i]);
    }
  }
  cout<<last.size()<<endl;
  return 0;
}
