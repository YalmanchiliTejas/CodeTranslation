#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <queue>
using namespace std;
int main(){
string s;
int l;
int a[26]={0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0};

while(cin>>s && s!="#"){
l=s.length();
int ans=0;
if(l!=1){
for(int i=0;i<l-1;i++){
if(a[s[i]-'a']+a[s[i+1]-'a']==1) ans++;
}
}
cout<<ans<<endl;
}

return 0;
}