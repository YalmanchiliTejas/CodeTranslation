#include<iostream>
#include<algorithm>
using namespace std;
int s,a,b,ans;
char ch;
int main(){
  while(1){
    ans=-1;
    for(int i=0;i<5;i++){
      cin>>a>>b;
      if(a==0&&b==0&&i==0)return 0;
      if(a+b>ans)ans=a+b,ch='A'+i;
    }
    cout<<ch<<' '<<ans<<endl;
  }
}