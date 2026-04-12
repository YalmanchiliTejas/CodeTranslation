// Example program
#include <iostream>
#include <string.h>
#include <algorithm>  
#include<vector>
using namespace std;
int main()
{

  int n,b;
  cin>>n;
  int a[50][28];
  char s[1000];
  for(int i=0;i<50;i++)
      for(int j=0;j<28;j++) a[i][j]=0;
  for(int i=0;i<n;i++){
      cin>>s;
      for(int j=0;j<strlen(s);j++){ 
          a[i][s[j]-'a']++;
      }
}
  for(int i=0;i<26;i++){
      int min=30000;
      for(int j=0;j<n;j++){
        
           if(a[j][i]<min){
            min=a[j][i];   
           }
      }
      char c='a'+i;
     
      for(int j=0;j<min;j++){
          cout<<c;
      }
  }

}
