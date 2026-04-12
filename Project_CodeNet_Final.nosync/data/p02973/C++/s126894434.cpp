#include <bits/stdc++.h>
using namespace std;
int main() {

   int n;
   cin>>n;
  // int ans=0;
   multiset <int> st;
   for(int i=0;i<n;i++)
   {
       int x;
       cin>>x;
       if(i==0)
       {st.insert(x);
           continue ;}
       auto it=st.lower_bound(x);

     //  it--;
       if(it==st.begin())
       {
           st.insert(x);
       }
       else
           {
           it--;
           st.erase(it);
           st.insert(x);
           }

   }


   cout<<st.size();
}
