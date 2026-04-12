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
int x,sm;
int main(){
cin>>x;
sm=x*800;
sm-=x/15*200;
cout<<sm<<endl;
system("pause");
return 0;
}