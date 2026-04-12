#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#define pb(in,tmp) in.push_back(tmp)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) loop(i,0,b)
#define all(in) in.begin(),in.end()
using namespace std;
int main(){
int a[5];
char b[5]={'A','B','C','D','E'};
int c,d;
while(cin>>c>>d,c||d){
a[0]=c+d;
loop(i,1,5){
cin>>c>>d;
a[i]=c+d;
}
int max=0;
int mai;
rep(i,5){
if(max<a[i]){
max=a[i];
mai=i;
}
}
cout<<b[mai]<<" "<<max<<endl;
}
}