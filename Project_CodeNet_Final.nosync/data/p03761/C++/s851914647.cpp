
#include <iostream>
#include <cmath>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);++i)

using namespace std;
typedef long long ll;




int main(){
 
    int ans[26];
    int tmp[26];
    int n;
    cin>>n;
    
    
    rep(i,26)ans[i]=0;
    
    
    rep(i,n){
        string s;
        cin>>s;
        rep(i,26)tmp[i]=0;
        
        for(int j=0;j!=s.size();++j){
           int a= s[j]-'a';
            ++tmp[a];
        }
        if(i==0){
            rep(j,26){ans[j]=tmp[j];};
        }else{
            rep(j,26){ans[j]=ans[j]<=tmp[j]?ans[j]:tmp[j];};
        }
        
    }

    rep(i,26){
        for(int j=0;j<ans[i];++j){
            if(ans[j]!=100){
               cout<<(char)('a'+i);
            }
        }
    }
    
    cout<<endl;
}
