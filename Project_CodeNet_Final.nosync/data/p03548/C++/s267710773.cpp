#include<string>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
int x,y,z;
cin>>x>>y>>z;
x-=z;
int s=x/(y+z);
cout<<s<<endl;
return 0;
} 