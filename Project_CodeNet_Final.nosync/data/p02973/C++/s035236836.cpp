#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,a[200007];
int main()
{
    multiset<int>st;
    multiset<int>::	iterator it;
	cin>>n;
    for(i=0;i<n;i++)
      cin>>a[i];
    st.insert(a[0]);
    for(i=1;i<n;i++)
    {
      it = st.upper_bound(a[i]-1);
      if(it == st.begin())
      {
      	st.insert(a[i]);
      }
      else
      {
      	it--;
        st.erase(it);
        st.insert(a[i]);
      }
    }
  cout<<st.size()<<endl;
}