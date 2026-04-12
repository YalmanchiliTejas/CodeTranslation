#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  multiset<int> st;
  for(int i=0;i<n;++i){
    int tmp;cin>>tmp;
      auto it = st.lower_bound(tmp);
      if (it == st.begin()) 
        st.insert(tmp); 
      else { 
        it--; 
        st.erase(it); 
        st.insert(tmp);
        }    
    /*
    for(auto i:st){
      cout<<i<<" ";
    }cout<<endl;
	*/
  }
  cout<<st.size()<<endl;
  return 0;
}
