#include<iostream>
using namespace std;
int main(){
  string s;
  int a,b,c,d,ind;
  cin >> s;
  while(s!="#"){
    int h=0,e_size;
    cin >> a >> b >> c >> d;
    string s_map[10];
    string ans;
    fill(s_map,s_map+10,"");
    for(int i=0;i<s.size();i++){
      if(s[i]=='/'){
        h++;
      }else if(s[i]=='b'){
        s_map[h]+='b';
      }else{
        e_size=(s[i]-'0');
        while(e_size!=0){
          s_map[h]+='.';
          e_size--;
        }
      }
    }
    a--; b--; c--; d--;
    if(s_map[a][b]=='b'){
      s_map[a][b]='.';
      s_map[c][d]='b';
    }
    for(int i=0;i<=h;i++){
      for(int j=0;j<s_map[i].size();j++){
        if(s_map[i][j]=='b'){
          ans+='b';
        }else{
          ind=j;
          while(ind<s_map[i].size()&&s_map[i][ind]=='.'){
            ind++;
          }
          ans+=to_string(ind-j);
          j=ind-1;
        }
      }
      if(i!=h)ans+='/';
    }
    cout << ans<<endl;
    cin >> s;
  }
}

