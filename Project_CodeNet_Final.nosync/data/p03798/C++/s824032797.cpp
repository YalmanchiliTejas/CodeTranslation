#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int n;
string s;
vector<char> v;

bool dfs(int idx){
    if(idx == n-1){
        if(s[idx] == 'o' ){
            if((v[idx] == 'W' && v[idx-1] == 'W') || (v[idx] == 'S' && v[idx-1] == 'S')){
                if(v[0] == 'S') {
                    return dfs(idx+1);
                }
                else return false;
            }
            else {
                if(v[0] == 'S') return false;
                else {
                    return dfs(idx+1);
                }
            }
        }
        else {
            if((v[idx] == 'W' && v[idx-1] == 'W') || (v[idx] == 'S' && v[idx-1] == 'S')){
                if(v[0] == 'S') return false;
                else {
                    return dfs(idx+1);
                }
            }
            else {
                if(v[0] == 'S') {
                    return dfs(idx+1);
                }
                else return false;
            }
        }
    }
    else if(idx == n){
        if(s[0] == 'o'){
            if(v[0] == 'S' && v[idx-1] == v[1] || v[0] == 'W' && v[idx-1] != v[1]){
                return true;
            }
            else return false;
        }
        else{
            if(v[0] == 'S' && v[idx-1] == v[1] || v[0] == 'W' && v[idx-1] != v[1]){
                return false;
            }
            else return true;
        }
    }
    else{
        if(s[idx] == 'o'){
            if((v[idx] == 'W' && v[idx-1] == 'W') || (v[idx] == 'S' && v[idx-1] == 'S')){
                v.push_back('S');
            }
            else v.push_back('W');
            return dfs(idx+1);
        }
        else{
            if((v[idx] == 'W' && v[idx-1] == 'W') || (v[idx] == 'S' && v[idx-1] == 'S')){
                v.push_back('W');
            }
            else v.push_back('S');
            return dfs(idx+1);
        }
    }
}
 
int main(void){
    cin>>n;
    cin>>s;
    vector<char> kouho[4];
    kouho[0] = {'S', 'S'};
    kouho[1] = {'S', 'W'};
    kouho[2] = {'W', 'S'};
    kouho[3] = {'W', 'W'};
    rep(i, 4){
        v = kouho[i];
        if(dfs(1)){
            rep(i, v.size()) cout<<v[i];
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}