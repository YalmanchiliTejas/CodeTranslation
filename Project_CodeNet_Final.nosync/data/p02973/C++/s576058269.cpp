#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
  int N; cin>>N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }

  multiset<int> st;
  st.insert(a[0]);

  for(int i=1;i<N;i++){
    auto itr=st.lower_bound(a[i]);
    if(itr==st.begin()){
      st.insert(a[i]);
    }else{
      itr--;
      st.erase(itr);
      st.insert(a[i]);
    }
  }
  
/*
  for(int x:st){
    cout<<x<<' ';
  }
  cout<<endl;
*/
  cout<<st.size()<<endl;
  
  return 0;
}
