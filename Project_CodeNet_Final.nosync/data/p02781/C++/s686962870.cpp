#include<bits/stdc++.h>
using namespace std;

int n,K,ans;
char s[105];
int f[105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s+1;
    cin>>K;
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        f[i]=(s[i]!='0')+f[i-1];
    }
    if(K==3){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<=n;k++){
                    if(f[i-1]){
                        ans+=729;
                    }else if(f[j-1]-f[i]>0){
                        if(s[i]>'0')ans+=(s[i]-'0')*81;
                    }else if(f[k-1]-f[j]>0){
                        if(s[i]>'1')ans+=(s[i]-'1')*81;
                        if(s[i]>'0')ans+=(s[j]-'0')*9;
                    }else{
                        //num i == s i
                        //num j == s j
                        if(s[i]>'0'&&s[j]>'0')ans+=s[k]-'0';
                        //num j < s j
                        if(s[i]>'0'&&s[j]>'1')ans+=(s[j]-'1')*9;
                        //num i < s i
                        if(s[i]>'1')ans+=(s[i]-'1')*81;
                    }
                }
            }
        }
    }
    if(K==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(f[i-1]){
                    ans+=81;
                }else if(f[j-1]-f[i]>0){
                    ans+=(s[i]-'0')*9;
                }else{
                    if(s[i]>'1')ans+=(s[i]-'1')*9;
                    if(s[i]>'0')ans+=s[j]-'0';
                }
            }
        }
    }
    if(K==1){
        for(int i=1;i<=n;i++){
            if(f[i-1]){
                ans+=9;
            }else{
                ans+=s[i]-'0';
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}