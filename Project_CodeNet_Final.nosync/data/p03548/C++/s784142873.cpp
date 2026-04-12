#include <iostream>
using namespace std;
 
int main(){
int a=0,b=0,c=0;
int ans =0;
 
cin >>a>>b>>c;
 
int len=b+c;
 
for(int i=1;len*i<=a-c;i++){
ans =i;
}
 
cout << ans<<endl;
 
return 0;
}