#include<bits/stdc++.h>
using namespace std;
int r,g,b;
int main(){
cin>>r>>g>>b;
if((r*100+g*10+b)%4==0)puts("YES");
else puts("NO");
}