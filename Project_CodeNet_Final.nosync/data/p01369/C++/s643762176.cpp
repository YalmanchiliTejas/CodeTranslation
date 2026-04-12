#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
  int m;
  char a[33];
  char b1[11]={'y','u','i','o','p','h','j','k','l','n','m'},b2[15]={'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};

  while(1){
    int count=0;

    scanf("%s",a);
    m=strlen(a);
    for(int i=0;i<m;i++)
      if(a[i]=='#')
	m--;
    if(m==0)break;
    
    for(int i=0;i<m;i++)
      for(int j=0;j<11;j++)
	if(a[i]==b1[j])
	  for(int k=0;k<15;k++)
	    if(a[i+1]==b2[k])count++;

    for(int i=0;i<m;i++)
      for(int j=0;j<15;j++)
	if(a[i]==b2[j])
	  for(int k=0;k<11;k++)
	    if(a[i+1]==b1[k])count++;
    
    cout<<count<<endl;
  }
  return 0;
}