#include<iostream>
#include<string>
using namespace std;
main(){for(int a,b,d,n;cin>>n,n;){string r;int c[3]={1,2,3},s=1;for(;n>0&&cin>>r;n--){a=1,b=0;if(r=="East")a=0,b=2;if(r=="West")a=2,b=0;if(r=="South")a=0,b=1;if(r=="Right")a=2,b=1;if(r=="Left")a=1,b=2;d=c[a];c[a]=7-c[b];c[b]=d;s+=c[0];}cout<<s<<"\n";}}