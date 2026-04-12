#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,x;
  cin>>n;
  vector<int>v(n);
  vector<int>::iterator it;
  for(int i=0;i<n;i++)
  cin>>v[i];
  int q;
  cin>>q;
  while(q--)
{
    cin>>x;

  // if(binary_search(v.begin(),v.end(),x))
  it= lower_bound(v.begin(),v.end(),x);
  if(it != v.end())
   cout<< lower_bound(v.begin(),v.end(),x)-v.begin()<<endl;
   else
    cout<<n<<endl;
}
return 0;
}

