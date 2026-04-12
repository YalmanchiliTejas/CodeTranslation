#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
typedef long long ll;

int main(){
  int n;
  cin>>n;
  multiset<int>st;
  int ans=0;
  rep(i,n){
    int a;
    scanf("%d",&a);
    auto it=st.lower_bound(a);
    if(it==st.begin()){
      ans++;
      st.insert(a);
    }
    else{
      --it;
      st.erase(it);
      st.insert(a);
    }
  }
  cout<<ans<<endl;
  return(0);
}
