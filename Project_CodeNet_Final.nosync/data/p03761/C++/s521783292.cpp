#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#define rep(i,n) for(ll i=0;i<n;i++)
typedef int long long ll;
using namespace std;
int const INF = 1000000;
int main(){
    int n;
    cin>>n;
    string s[n];
    rep(i,n){
        cin>>s[i];
    }
    int alpha[26];rep(i,26){alpha[i]=0;}
   
        rep(j,s[0].size()){
            alpha[s[0][j]-'a']++;
        }
    for(int i=1;i<n;i++){
        int al[26];rep(k,26){al[k]=0;}
        rep(j,s[i].size()){al[s[i][j]-'a']++;}
        rep(k,26){if(al[k]<alpha[k]){alpha[k]=al[k];}}
    }
    
    
    string ans;
    rep(i,26){if(alpha[i]!=0){
       /* while(alpha[i]!=0){
            ans+=char(i+'a');
            alpha[i]--;
        }*/
        ans+=string(alpha[i],char(i+'a'));
    }}
    cout<<ans<<endl;
    return 0;
}
