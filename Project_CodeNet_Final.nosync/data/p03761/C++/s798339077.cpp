#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n;
    int a[128];
    int b[128];
    string ans="";
    rep(i,128) a[i]=0;
    cin>>n;
    rep(i,n){
        string s;
        cin>>s;
        int ss=s.size();
        rep(j,128) b[j]=0;
        rep(j,ss){
            if(i==0){
                a[s[j]]++;
            }else{
                b[s[j]]++;
            }
        }
        for(char j='a';j<='z';j++){
            if(i!=0){
                a[j]=min(a[j],b[j]);
            }
        }
    }
    for(char i='a';i<='z';i++){
        rep(j,a[i]){
            ans.push_back(i);
        }
    }
    cout<<ans<<endl;
}
