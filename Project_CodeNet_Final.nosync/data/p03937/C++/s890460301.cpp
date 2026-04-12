#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  int i,j;
  for(i=0;i<h;i++){
    cin >> s[i];
  }
  i=0;
  j=0;
  int chk = 1;
  s[0][0]='.';
  while(i!=w-1 || j != h-1){
    if(j<h-1&&s[j+1][i]=='#'){
      j++;
      s[j][i]='.';
    }else if(i<w-1&&s[j][i+1]=='#'){
      i++;
      s[j][i]='.';
    }else{
      chk = 0;
      break;
    }
  }
  
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(s[i][j]=='#')chk=0;
    }
  }
  if(chk==0)cout<<"Impossible"<<endl;
  else cout << "Possible"<<endl;

}
