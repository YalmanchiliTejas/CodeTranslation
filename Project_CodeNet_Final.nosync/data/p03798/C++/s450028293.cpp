#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#define ll long long int
#define MOD 1000000007LL
using namespace std;
int main() {
    int n;
    string s;
    cin>>n;
    cin>>s;
    char ans[114514]={};
    for(int i=0;i<2;i++){
        if(i==0){
            ans[0]='S';
        }else{
            ans[0]='W';
        }
        for(int j=0;j<2;j++){
            if(j==0){
                ans[1]='S';
            }else{
                ans[1]='W';
            }
            bool f=true;
            for(int k=2;k<n;k++){
                if(ans[k-1]=='S'){
                    if(ans[k-2]=='W'){
                        if(s[k-1]=='o'){
                            ans[k]='W';
                        }else{
                            ans[k]='S';
                        }
                    }else{
                        if(s[k-1]=='o'){
                            ans[k]='S';
                        }else{
                            ans[k]='W';
                        }
                    }
                }else{
                    if(ans[k-2]=='W'){
                        if(s[k-1]=='o'){
                            ans[k]='S';
                        }else{
                            ans[k]='W';
                        }
                    }else{
                        if(s[k-1]=='o'){
                            ans[k]='W';
                        }else{
                            ans[k]='S';
                        }
                    }
                }
            }
            for(int i=0;i<n;i++){
                int l,r;
                if(i==0){
                    l=n-1;
                    r=1;
                }else if(i==n-1){
                    l=n-2;
                    r=0;
                }else{
                    l=i-1;
                    r=i+1;
                }
                if(s[i]=='o'){
                    if(ans[i]=='S'){
                        if(ans[l]!=ans[r]){
                            f=false;
                        }
                    }else{
                        if(ans[l]==ans[r]){
                            f=false;
                        }
                    }
                }else{
                    if(ans[i]=='W'){
                        if(ans[l]!=ans[r]){
                            f=false;
                        }
                    }else{
                        if(ans[l]==ans[r]){
                            f=false;
                        }
                    }
                }
            }
            if(f==true){
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}