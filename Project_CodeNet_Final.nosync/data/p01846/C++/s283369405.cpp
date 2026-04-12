#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main(){
  while(1){
    string s;
    int a,b,c,d;
    cin >> s;
    if(s[0]=='#')break;
    int w=0;
    int h=1;
    int i,j,k;
    for(i=0;i<s.size();i++){
      if(h==1){
	if(s[i]!='/'){
	  if(s[i]=='b')w++;
	  else w+=s[i]-'0';
	}
	else h++;
      }
      else if(s[i]=='/')h++;
    }
    vector<vector<int> >m(h,vector<int>(w,0));
    i=0;
    j=0;
    for(k=0;k<s.size();k++){
      if(s[k]=='/')continue;
      if(s[k]=='b'){
	m[i][j]=1;
	j++;
      }
      else{
	int l=s[k]-'0';
	for(int I=0;I<l;I++)m[i][j+I]=0;
	j+=l;
      }
      if(j==w){
	i++;
	j=0;
      }
    }
    cin >> a >> b >> c >> d;
    m[a-1][b-1]=0;
    m[c-1][d-1]=1;
    int co=0;
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	if(m[i][j]==1){
	  if(co>0){
	    cout << co;
	    co=0;
	  }
	  cout << 'b';
	}
	else co++;
      }
      if(co>0){
	cout << co;
	co=0;
      }
      if(i+1!=h)cout << '/' ;
    }
    cout << endl;
  }
  return 0;
}