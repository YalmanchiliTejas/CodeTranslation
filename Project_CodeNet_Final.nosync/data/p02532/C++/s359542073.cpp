#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

struct Q{string y;};

int main(){

int n[1001][101];
struct Q q[1001];
string x;
int p,pp;
string st;
     
scanf("%d",&n);

while(1){
cin>>st;

if(st=="push"){cin>>p>>x;
q[p].y=q[p].y+x;}
if(st=="pop"){cin>>p;cout<<q[p].y[(q[p].y.size())-1]<<endl;
//cout<<q[p].y[(q[p].y.size())];
q[p].y.erase(q[p].y.size()-1);}
//q[p].y=q[p].y-q[p].y[(q[p].y.size())];}

if(st=="move"){cin>>p>>pp;

q[pp].y=q[pp].y+q[p].y[(q[p].y.size())-1];
q[p].y.erase(q[p].y.size()-1);}
//q[p].y=q[p].y+q[p].y[(q[p].y.size())];}
if(st=="quit")break;
}
return 0;
}