#include<bits/stdc++.h>

using namespace std;

#define MAX 100005
#define pb push_back

/*
    we need to find longest non decreasing sequence and at each step, we need to search for an element that is closest to the current element, 
    i.e. largest number statisfying a[i]<a[j] so that we have maximum options available for next number. 
*/

int main(){
  int n,a;
  cin>>n;
  multiset<int> ans;
  cin>>a;
  ans.insert(-a);
  for(int i=1;i<n;i++){
    cin>>a;
    a*=-1;
    auto itr=ans.lower_bound(a);
    if(itr!=ans.end()){
        if(*itr==a){
            int b=a+1;
            auto it=ans.lower_bound(b);
            if(it!=ans.end()){
                ans.erase(it);
            }
        }
        else{
            ans.erase(itr);
        }
    }
    ans.insert(a);
  }
  cout<<ans.size()<<endl;
	return 0;
}
