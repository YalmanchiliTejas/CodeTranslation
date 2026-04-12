#include<iostream>
using namespace std;
int main(){
long s[5],a,b,i,m,mm;
while(cin>>a>>b,a*a+b*b){
s[0]=a+b;
for(i=1;i<5;i++){
cin>>a>>b;
s[i]=a+b;
}
for(m=s[0],mm=0,i=1;i<5;i++)if(m<s[i]){m=s[i];mm=i;}
cout<<"ABCDE"[mm]<<" "<<m<<endl;
}
return 0;
}