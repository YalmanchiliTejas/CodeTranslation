#include<vector>
#include<list>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  int h,i,j,k;
  int a[1000],m,n;
  while(cin>>m>>n&&m+n){
    for(i=0;i<m;i++)
      a[i]=i+1;
    j=0;
    for(i=1;i<n+1;i++){
      string s;
      cin>>s;
      if(i%3==0&&i%5==0)
	h=s=="FizzBuzz";
      else if(i%3==0)
	h=s=="Fizz";
      else if(i%5==0)
	h=s=="Buzz";
      else
	h=atoi(s.c_str())==i;
      if(m!=1&&h==0){
	for(k=0;k<m-j-1;k++)
	  a[j+k]=a[j+k+1];
	j--;
	m--;
      }
      j=(j+1)%m;
    }
    for(i=0;i<m-1;i++)
      cout<<a[i]<<" ";
    cout<<a[i]<<endl;
  }
  return 0;
}