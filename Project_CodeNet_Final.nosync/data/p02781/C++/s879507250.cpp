#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
  string s;int n,k;cin>>s>>k;n=s.size();
  long long ans=0;
  string ttmp=""; REP(tt,n) ttmp.push_back('0');
  if(k==1){
    ans+=9*(n-1);
    int top=s.at(0)-'0';
    ans+=top;
  }else if(k==2){
    for(int i=2;i<n;i++) ans+=9*9*(i-1);
    for(int i=1;i<=9;i++){
      for(int j=1;j<=9;j++){
        for(int l=1;l<n;l++){
          string tmp=ttmp;
          //REP(tt,n) tmp.push_back('0');
          tmp.at(0)=i+'0';
          tmp.at(l)=j+'0';
          REP(tt,n){
            if(tmp.at(tt)<s.at(tt)){
              ans++;
              break;
            }else if(tmp.at(tt)>s.at(tt)){
              break;
            }else{
              if(tt==n-1) ans++;
            }
          }
        }  
      }
    }  
  }else{
    for(int i=3;i<n;i++) ans+=9*9*9*(i-1)*(i-2)/2;
    for(int i=1;i<=9;i++){
      for(int j=1;j<=9;j++){
        for(int jj=1;jj<=9;jj++){
          for(int l=1;l<n-1;l++){
            for(int ll=l+1;ll<n;ll++){
              string tmp=ttmp;
              //REP(tt,n) tmp.push_back('0');
              tmp.at(0)=i+'0';
              tmp.at(l)=j+'0';
              tmp.at(ll)=jj+'0';
              REP(tt,n){
                if(tmp.at(tt)<s.at(tt)){
                  ans++;
                  break;
                }else if(tmp.at(tt)>s.at(tt)){
                  break;
                }else{
                  if(tt==n-1) ans++;
                }
              }
            }
          }  
        }
      }
    }
  }
  cout<<ans<<endl;;
}