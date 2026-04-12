#include <iostream>
using namespace std;
main(){
int s,t;
while(cin>>s>>t){
if((s||t)==0) break;
int m=s+t,mi=0;
for(int i=1;i<5;i++){
cin>>s>>t;
if(m<s+t){
m=s+t;
mi=i;
}
}
cout<<(char)('A'+mi)<<" "<<m<<endl; 
}
}