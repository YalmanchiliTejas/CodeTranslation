#include<bits/stdc++.h>
using namespace std;
#define minc *(c.begin())
#define maxc *(c.end()-1)
main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(auto& i:a)cin>>i;
  vector<int> c;
  c.push_back(a[n-1]);
  //for(auto k:c)cerr<<" "<<k;
  //cerr<<"  ["<<minc<<","<<maxc<<"]("<<a[n-1]<<")\n"<<flush;
  for(int i=n-2;i>=0;--i){
    if(a[i]<minc)c[0]=a[i];
    else if(maxc<=a[i])c.push_back(a[i]);
    else {
      auto itr=lower_bound(c.begin(),c.end(),a[i]+1);
      int k=*itr;
      c.erase(itr);
      assert(a[i]<k);
      auto itr2=c.insert(lower_bound(c.begin(),c.end(),a[i]),a[i]);
      if(itr2==c.end()-1)maxc=*(c.end()-1);
      else if(itr2==c.begin())minc=c[0];
    }
    //for(auto k:c)cerr<<" "<<k;
    //cerr<<"  ["<<minc<<","<<maxc<<"]("<<a[i]<<")\n"<<flush;
  }
  cout<<c.size();
}