#include <iostream>
#include <string>

using namespace std;

int main(){
  string N;
  int K;
  cin >> N >> K;
  int ans=0;
  if(K==1) cout << 9*(N.size()-1)+(N[0]-'0') << endl;
  if(K==2){
    if(N.size()==1) cout << 0 << endl;
    else{
      for(int i=2; i<N.size(); i++) ans+=81*(i-1);
      ans+=(N[0]-'0'-1)*9*(N.size()-1);
      for(int i=1; i<N.size(); i++){
        if(N[i]!='0'){
          ans+=(N[i]-'0')+9*(N.size()-i-1);
          break;
        }
      }
      cout << ans << endl;
    }
  }
  bool endflag=false;
  if(K==3){
    if(N.size()<=2) cout << 0 << endl;
    else{
      for(int i=3; i<N.size(); i++) ans+=729*(i-1)*(i-2)/2;
      ans+=(N[0]-'0'-1)*81*(N.size()-1)*(N.size()-2)/2;
      for(int i=1; i<N.size(); i++){
        if(N[i]!='0'){
          ans+=(N[i]-'0'-1)*9*(N.size()-i-1);
          ans+=81*(N.size()-i-1)*(N.size()-i-2)/2;
          for(int j=i+1; j<N.size(); j++){
            if(N[j]!='0'){
              ans+=(N[j]-'0')+9*(N.size()-j-1);
              endflag=true;
              break;
            }
          }
        }
        if(endflag) break;
      }      
      cout << ans << endl;
    }
  }
  
  return 0;
}