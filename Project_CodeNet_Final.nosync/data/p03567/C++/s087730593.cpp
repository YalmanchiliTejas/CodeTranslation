#include<iostream>
#include<string>
using namespace std;;
int main(void){
string a;
cin >>a;
int i=a.length();
int flag=0;
for(int j=0;j<i-1;j++){
if(a[j]=='A'&&a[j+1]=='C'){
flag=1;
}
}
if(flag==1){
cout<<"Yes";
}
else{
cout<<"No";
}
return 0;
}