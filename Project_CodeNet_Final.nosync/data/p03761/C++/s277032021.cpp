#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define rep(i, n) for(int i = 0; i < (n); i++)

int n,cnt[50][30];
string s[50];
char res[51];
 
int main() {
    cin>>n;
    int index=0;
    rep(i,n) cin>>s[i];
    rep(i,n) rep(j,s[i].size()) cnt[i][s[i][j]-'a']++;
    rep(i,26){
        int c=cnt[0][i];
        for (int k=1;k<n;k++){
            c=min(c,cnt[k][i]);
        }
        for (int k=index;k<index+c;k++) {
            res[k]='a'+i;
        }
        index+=c;
    }
    cout<<res<<endl;  
}