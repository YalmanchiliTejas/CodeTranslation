#include<bits/stdc++.h>
using namespace std;

int main(){
 int a,c;
  cin>>a;
  vector<int>b(a);
  c=0;
  for(int i=0;i<a;i++){
    cin>>b[i];
    if(i>0){
      if(b[i]>=b[i-1]){
c++;
  }
      b[i]=max(b[i],b[i-1]);
    }
     }

       cout<<c+1<<endl;
}
