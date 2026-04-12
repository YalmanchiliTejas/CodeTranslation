#include<bits/stdc++.h>
using namespace std;
int main(){
int X,Y,Z;
cin>>X>>Y>>Z;
int i=X/(Y+Z),j=X-(i*(Y+Z));
if(j>=Z)cout<<i;
else cout<<i-1;
return 0;
}
