#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin>>n>>q;
  int om=0;
  for(int i=0; i<q; i++){
    int q1,q2;
    cin>>q1>>q2;
    
    if(q1==1){
      om=(om+q2)%n;
    }else{
      cout<<((q2+om-1)%n)+1<<endl;
    }
  }
}
