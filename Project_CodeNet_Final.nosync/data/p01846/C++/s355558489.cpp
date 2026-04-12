#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,n;
  while(cin>>s,s!="#"){
    int i,j,k,x=0,y=0,a,b,c,d;
    bool m[10][10];
    memset(m,0,sizeof(m));
    for(i=0;i<s.size();i++){
      if(s[i]=='/') x=0,y++;
      else if(isdigit(s[i])) x+=s[i]-'0';
      else m[x++][y]=1;
    }
    cin>>a>>b>>c>>d;
    a--;b--;c--;d--;
    m[b][a]=0;m[d][c]=1;
    n="";
    for(i=0;i<y+1;i++){
      k=0;
      for(j=0;j<x;j++){
	if(m[j][i]){
	  if(k) n+=('0'+k);k=0;
	  n+="b";
	}else k++;      
      }
      if(k) n+=('0'+k);k=0;
      if(i!=y) n+="/";
    }
    cout << n << endl;
  }
  return 0;
}