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
  for(int x:a){
    auto itr=st.lower_bound(x);
    if(itr==st.begin()){
      st.insert(x);
    }else{
      itr--;
      st.erase(itr);
      st.insert(x);
    }
  }
  cout<<st.size()<<endl;

  return 0;
}
