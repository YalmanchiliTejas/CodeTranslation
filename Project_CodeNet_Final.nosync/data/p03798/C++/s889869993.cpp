#include<bits/stdc++.h>
using namespace std;

string s; 

void solve(bool ans[],int N){
    for(int i=1;i<N-1;i++){
        if(s[i]=='o'&&ans[i]==true){
            ans[i+1]=ans[i-1];
        }else if(s[i]=='x'&&ans[i]==true){
            ans[i+1]=1-ans[i-1];
        }else if(s[i]=='o'&&ans[i]==false){
            ans[i+1]=1-ans[i-1];
        }else{
            ans[i+1]=ans[i-1];
        }
    }
}

bool check(bool ans[],int N){
    if((ans[N-1]==true&&s[N-1]=='o')||(ans[N-1]==false&&s[N-1]=='x')){
        if(ans[N-2]!=ans[0]){
            return false;
        }
    }
    if((ans[N-1]==true&&s[N-1]=='x')||(ans[N-1]==false&&s[N-1]=='o')){
        if(ans[N-2]==ans[0]){
            return false;
        }
    }
    if((ans[0]==true&&s[0]=='o')||(ans[0]==false&&s[0]=='x')){
        if(ans[N-1]!=ans[1]){
            return false;
        }
    }
    if((ans[0]==true&&s[0]=='x')||(ans[0]==false&&s[0]=='o')){
        if(ans[N-1]==ans[1]){
            return false;
        }
    }
    return true;
}

int main(){
    int N; cin >> N;
    cin >> s;
    bool ans[N];
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            ans[0]=i; ans[1]=j;
            solve(ans,N);
            if(check(ans,N)){
                for(int i=0;i<N;i++){
                    if(ans[i]==true) cout << 'S';
                    else cout << 'W';
                }
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}