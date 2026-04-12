#include <iostream>
using namespace std;
int main(){
int n,k,i;
cin>>n;
char s[n];
cin >>s>>k;
for(i=0;i<n;i++){
if(s[i]!=s[k-1]) s[i]='*';
}
cout<<s<<endl;
return 0;
}