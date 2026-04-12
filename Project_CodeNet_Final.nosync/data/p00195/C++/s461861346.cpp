#include<iostream>
using namespace std;
int main(){int p[5],tmp,ans;char n[5]={'A','B','C','D','E'};while(1){ans=0;for(int i=0;i<5;i++){cin>>p[i]>>tmp;p[i]+=tmp;if(!p[0])return 0;if(p[ans]<p[i])ans=i;}cout<<n[ans]<<' '<<p[ans]<<endl;}}