#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    int n;
    cin>>n;
    string s[n];
    rep(i,n)cin>>s[i];

    int alp[n][26] = {0};
    rep(i,n){
        rep(j,s[i].size()){
            rep(k,26){
                if(s[i][j] == 'a'+k){
                    ++alp[i][k];
                }
            }
        }
    }

    int ans_alp[26];
    rep(i,26) ans_alp[i] = 100;
    rep(i,26){
        rep(j,n){
            ans_alp[i] = min(ans_alp[i],alp[j][i]);
        }
    }

    rep(i,26){
        rep(j,ans_alp[i]){
            printf("%c",'a'+i);
        }
    }
    /*rep(i,26){
        printf("%d ",ans_alp[i]);
    }printf("\n");
    rep(i,n){
        rep(j,26){
            printf("%d ",alp[i][j]);
        }
        printf("\n");
    }*/
}