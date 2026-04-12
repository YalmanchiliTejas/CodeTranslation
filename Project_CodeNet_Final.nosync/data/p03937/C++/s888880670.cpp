#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  int x=0,y=0;
  for(int i=0;i<h;i++){
    cin>>s[i];
  }
  while(x<w&&y<h){
    if(x==w-1&&y==h-1) break;
    if(x==w-1){
      if(s[y+1].at(x)=='#'){
        if(s[y+1].at(x-1)=='#'){
          cout<<"Impossible"<<endl;
          return 0;
        }
        y++;
      }else{
        cout<<"Impossible"<<endl;
        return 0;
      }
    }else if(y==h-1){
      if(s[y].at(x+1)=='#'){
        if(s[y-1].at(x+1)=='#'){
          cout<<"Impossible"<<endl;
          return 0;
        }
        x++;
      }else{
        cout<<"Impossible"<<endl;
        return 0;
      }
    }
    else if(s[y].at(x+1)=='#'){
      if(y!=0){
        if(s[y-1].at(x+1)=='#'){
          cout<<"Impossible"<<endl;
          return 0;
        }
      }
      if(s[y+1].at(x)=='#'){
        cout<<"Impossible"<<endl;
        return 0;
      }else x++;
    }else if(s[y+1].at(x)=='#'){
      if(s[y].at(x+1)=='#'){
        cout<<"Impossible"<<endl;
        return 0;
      }else y++;
    }else{
      cout<<"Impossible"<<endl;
      return 0;
    }
  }
  if(s[h-1].at(w-1)=='#'){
    cout<<"Possible"<<endl;
  }else cout<<"Impossible"<<endl;
}
