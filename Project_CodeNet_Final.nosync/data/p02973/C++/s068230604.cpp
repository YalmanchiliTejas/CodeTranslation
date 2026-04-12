#include<bits/stdc++.h>
using namespace std;
 
int main(){
  long int n,i,d;
  cin>>n;
  
    multiset<long int>last;
    for(i=0;i<n;i++){
      
      cin>>d;
      multiset<long int>::iterator it = last.lower_bound(d);
      if(it==last.begin())
        last.insert(d);
      else{
        it--;
        last.erase(it);
        last.insert(d);
      }
    }
    cout<<last.size();
  
  return 0;
}