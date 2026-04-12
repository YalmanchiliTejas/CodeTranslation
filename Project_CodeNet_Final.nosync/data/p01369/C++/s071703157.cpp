#include <iostream>

using namespace std;

int main(){
  char c[]={'y','u','i','o','p','h','j','k','l','n','m'};
  string s;
  bool flag=false,right;
  while(cin >> s,s[0]!='#'){
    int i,ans=0;
    for(i=0;i<s.size();i++){
      right = false;
      for(int j=0;j<11;j++){
        if(s[i]==c[j])right = true;
      }
      if(right){
        if(i==0)flag = true;
        if(!flag){
          flag = true;
          ans++;
        }
      }else{
        if(i==0)flag =false;
        if(flag){
          flag = false;
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

