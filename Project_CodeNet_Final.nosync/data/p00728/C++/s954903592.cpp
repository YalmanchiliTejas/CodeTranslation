#include<iostream>
#include<set>
using namespace std;

int main()
{
  int n,s,i,sum;
  multiset<int> ms;
  multiset<int>::iterator it,ite;
  while(cin>>n,n){
    ms.clear();
    for(i=0;i<n;i++){
      cin>>s;
      ms.insert(s);
    }
    sum=0;
    ite=ms.end();
    ite--;
    it=ms.begin();
    for(it++;it!=ite;it++)sum+=*it;
    cout<<sum/(n-2)<<endl;
  }
}