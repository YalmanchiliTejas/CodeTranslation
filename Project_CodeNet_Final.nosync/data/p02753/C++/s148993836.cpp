#include<bits/stdc++.h>

using namespace std;
int main()
{
          char c;
          string s;
          cin>>s;
          set<int>st;
          for(int i=0;i<s.size();i++)
          {
                st.insert(s[i]);
          }
          if(st.size()==2)
                    cout<<"Yes";
          else cout<<"No";

}
