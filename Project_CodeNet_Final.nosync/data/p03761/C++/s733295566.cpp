#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

 
int main() {
    int n;
    cin>>n;
    map<char,int> S;
    string s1;
    cin>>s1;
    rep(i,s1.length()){
        S[s1[i]]++;
    }

    for(int i=1;i<n;i++){
       string sf;
       cin>>sf;
       map<char,int> SF;
       rep(i,sf.length()){
        SF[sf[i]]++;
       }
       for(auto p:S){
           if(SF.count(p.first))S[p.first]=min(SF[p.first],S[p.first]);
           else S.erase(p.first);
       }
 
    }
    
    for(auto p:S){
        rep(i,p.second)cout<<p.first;
    }

}