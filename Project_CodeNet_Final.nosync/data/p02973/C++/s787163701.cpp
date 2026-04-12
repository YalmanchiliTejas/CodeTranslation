#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
  int N; cin>>N;
  multiset<int> st;
  for(int i=0;i<N;i++){
    int x; cin>>x;
    auto itr=st.lower_bound(x);
    if(itr!=st.begin()){
      st.erase(prev(itr));
    }
    st.insert(x);
  }
  cout<<st.size()<<endl;

  return 0;
}
