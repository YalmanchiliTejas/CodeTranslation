#include<iostream>
#include<string>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int N;
    string s;
    string ans;
    cin >> N; 
    cin >> s;
    string s0 = "SSWW";
    string s1 = "SWSW";
    bool check1=false;
    bool check2=false;
    for(int i=0; i<4; i++){
        ans.clear();
        ans.push_back(s0[i]);
        ans.push_back(s1[i]);
        for(int j=1; j<N-1; j++){
            if(ans[j]=='S'){
                if(s[j]=='o'){
                    ans.push_back(ans[j-1]);
                }else{
                    if(ans[j-1]=='S'){
                        ans.push_back('W');
                    }else{
                        ans.push_back('S');
                    }
                }
            }else{
                if(s[j]=='x'){
                    ans.push_back(ans[j-1]);
                }else{
                    if(ans[j-1]=='S'){
                        ans.push_back('W');
                    }else{
                        ans.push_back('S');
                    }
                }
            }
        }
        //cout << ans << endl;
        if(s[N-1]=='o' && ans[N-1]=='S' && ans[N-2]==ans[0]){
            check1 = true;
        }
        if(s[N-1]=='o' && ans[N-1]=='W' && ans[N-2]!=ans[0]){
            check1 = true;
        }
        if(s[N-1]=='x' && ans[N-1]=='W' && ans[N-2]==ans[0]){
            check1 = true;
        }
        if(s[N-1]=='x' && ans[N-1]=='S' && ans[N-2]!=ans[0]){
            check1 = true;
        }
        if(s[0]=='o' && ans[0]=='S' && ans[N-1]==ans[1]){
            check2 = true;
        }
        if(s[0]=='o' && ans[0]=='W' && ans[N-1]!=ans[1]){
            check2 = true;
        }
        if(s[0]=='x' && ans[0]=='W' && ans[N-1]==ans[1]){
            check2 = true;
        }
        if(s[0]=='x' && ans[0]=='S' && ans[N-1]!=ans[1]){
            check2 = true;
        }
        if(check1 && check2){
            break;
        }else
        {
            check1=false;
            check2=false;
        }
        
    }
    if(check1 && check2){
        cout << ans << endl;
    }else{
        cout << "-1" << endl;
    }
    
    return 0;
}