#include<set>
#include<iostream>
using namespace std;

int main(){
  int l,r;
  for(;;){
    cin>>l>>r;
    if(l+r==0)break;

    set<unsigned int> pass;
    unsigned int t,max=0;

    pass.insert(0);

    for(int i=0;i<l+r;i++)
      cin>>t,pass.insert(t);

    set<unsigned int>::iterator it;
    for(it=pass.begin();it!=--pass.end();++it)
      if(*(++it)-*(--it)>max)max=*(++it)-*(--it);

    //if(l+r==1)max=*(pass.begin());
    cout<<max<<endl;
  }
}