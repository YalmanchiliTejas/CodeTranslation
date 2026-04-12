#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
  int N; cin>>N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }

  multiset<int> st;
  for(int i=0;i<N;i++){
    auto itr=st.lower_bound(a[i]);
    if(itr==st.begin()){
      st.insert(a[i]);
    }else{
      st.erase(prev(itr));
      st.insert(a[i]);
    }
  }
  cout<<st.size()<<endl;

  return 0;
}
