#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;
 
int main(){
    int n;
    string s;
    cin>>n>>s;
    string ans(n,'S');
    bool flag=false;
    if(s[0]=='o'){
        ans[1]='S';ans[n-1]='S';
        FOR(i,1,n){
            if(s[i]=='o'&&ans[i]=='S'||s[i]=='x'&&ans[i]=='W'){
                if(i==n-2){
                    if(ans[i+1]!=ans[i-1]){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==ans[i-1]){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=ans[i-1];
            }
            else{
                if(i==n-2){
                    if(ans[i+1]!=(ans[i-1]=='S'?'W':'S')){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==(ans[i-1]=='S'?'W':'S')){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=(ans[i-1]=='S'?'W':'S');
            }
        }
        ans[1]='W';ans[n-1]='W';
        FOR(i,1,n){
            if(s[i]=='o'&&ans[i]=='S'||s[i]=='x'&&ans[i]=='W'){
                if(i==n-2){
                    if(ans[i+1]!=ans[i-1]){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==ans[i-1]){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=ans[i-1];
            }
            else{
                if(i==n-2){
                    if(ans[i+1]!=(ans[i-1]=='S'?'W':'S')){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==(ans[i-1]=='S'?'W':'S')){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=(ans[i-1]=='S'?'W':'S');
            }
        }
    }
    else{
        ans[1]='S';ans[n-1]='W';
        FOR(i,1,n){
            if(s[i]=='o'&&ans[i]=='S'||s[i]=='x'&&ans[i]=='W'){
                if(i==n-2){
                    if(ans[i+1]!=ans[i-1]){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==ans[i-1]){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=ans[i-1];
            }
            else{
                if(i==n-2){
                    if(ans[i+1]!=(ans[i-1]=='S'?'W':'S')){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==(ans[i-1]=='S'?'W':'S')){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=(ans[i-1]=='S'?'W':'S');
            }
        }
        ans[1]='W';ans[n-1]='S';
        FOR(i,1,n){
            if(s[i]=='o'&&ans[i]=='S'||s[i]=='x'&&ans[i]=='W'){
                if(i==n-2){
                    if(ans[i+1]!=ans[i-1]){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==ans[i-1]){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=ans[i-1];
            }
            else{
                if(i==n-2){
                    if(ans[i+1]!=(ans[i-1]=='S'?'W':'S')){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==(ans[i-1]=='S'?'W':'S')){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=(ans[i-1]=='S'?'W':'S');
            }
        }
    }
    ans[0]='W';
    if(s[0]=='o'){
        ans[1]='W';ans[n-1]='S';
        FOR(i,1,n){
            if(s[i]=='o'&&ans[i]=='S'||s[i]=='x'&&ans[i]=='W'){
                if(i==n-2){
                    if(ans[i+1]!=ans[i-1]){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==ans[i-1]){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=ans[i-1];
            }
            else{
                if(i==n-2){
                    if(ans[i+1]!=(ans[i-1]=='S'?'W':'S')){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==(ans[i-1]=='S'?'W':'S')){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=(ans[i-1]=='S'?'W':'S');
            }
        }
        ans[1]='S';ans[n-1]='W';
        FOR(i,1,n){
            if(s[i]=='o'&&ans[i]=='S'||s[i]=='x'&&ans[i]=='W'){
                if(i==n-2){
                    if(ans[i+1]!=ans[i-1]){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==ans[i-1]){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=ans[i-1];
            }
            else{
                if(i==n-2){
                    if(ans[i+1]!=(ans[i-1]=='S'?'W':'S')){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==(ans[i-1]=='S'?'W':'S')){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=(ans[i-1]=='S'?'W':'S');
            }
        }
    }
    else{
        ans[1]='S';ans[n-1]='S';
        FOR(i,1,n){
            if(s[i]=='o'&&ans[i]=='S'||s[i]=='x'&&ans[i]=='W'){
                if(i==n-2){
                    if(ans[i+1]!=ans[i-1]){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==ans[i-1]){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=ans[i-1];
            }
            else{
                if(i==n-2){
                    if(ans[i+1]!=(ans[i-1]=='S'?'W':'S')){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==(ans[i-1]=='S'?'W':'S')){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=(ans[i-1]=='S'?'W':'S');
            }
        }
        ans[1]='W';ans[n-1]='W';
        FOR(i,1,n){
            if(s[i]=='o'&&ans[i]=='S'||s[i]=='x'&&ans[i]=='W'){
                if(i==n-2){
                    if(ans[i+1]!=ans[i-1]){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==ans[i-1]){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=ans[i-1];
            }
            else{
                if(i==n-2){
                    if(ans[i+1]!=(ans[i-1]=='S'?'W':'S')){
                        break;
                    }
                }
                if(i==n-1){
                    if(ans[0]==(ans[i-1]=='S'?'W':'S')){
                        cout<<ans<<endl;return 0;
                    }
                }
                else ans[i+1]=(ans[i-1]=='S'?'W':'S');
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}