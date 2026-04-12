#include<stdio.h>
#include<cstring>
 
bool isOk(char s[100]){
  int a;
  sscanf(s,"%d",&a);
  if(s[0]=='0'){
    if(s[1]=='\0')
      return true;
    else
      return false;
  }
  if( 0<=a && a<=255 )
    return true;
  else
    return false;
}
 
bool judge(char s[100],int i,int j,int k){
  char s1[4][100]={};
  int ind;
  int m[4]={};
  int n=strlen(s);
  for(ind=0; ind<n; ind++){
    if(ind<i){
      s1[0][m[0]]=s[ind];
      m[0]++;
    }
    else if(ind<j){
      s1[1][m[1]]=s[ind];
      m[1]++;
    }
    else if(ind<k){
      s1[2][m[2]]=s[ind];
      m[2]++;
    }
    else{
      s1[3][m[3]]=s[ind];
      m[3]++;
    }
  }
  if(!isOk(s1[0]))return false;
  if(!isOk(s1[1]))return false;
  if(!isOk(s1[2]))return false;
  if(!isOk(s1[3]))return false;
  return true;
}
 
int main(){
  
  char s[100];
  int i,j,k;
  int sum;
  int len;
  

    sum=0;
    scanf("%s",s);

    
    len=strlen(s);
    for(i=1;i<len-2;i++)
      for(j=i+1;j<len-1;j++)
	for(k=j+1;k<len;k++){
	  if(judge(s,i,j,k))
	    sum++;
	}
    printf("%d\n",sum);

  
}

