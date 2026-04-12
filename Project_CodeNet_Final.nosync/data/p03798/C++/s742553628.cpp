#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long ll;
const ll MOD = 1e9+7;

int n;
string s;
vector<int> ans(100001);
bool flag;

void l_search(void){
    // 全部埋める
    for(int i = 1; i < n-1; ++i){
        if(s[i] == 'o'){
            if(ans[i]){ // 羊
                ans[i+1] = ans[i-1];
            }else{ // 狼
                ans[i+1] = 1-ans[i-1];
            }
        }else{
            if(ans[i]) ans[i+1] = 1-ans[i-1];
            else ans[i+1] = ans[i-1];
        }
    }

    // 整合性の確認
    flag = true;
    rep(i,n){
        if(i == 0){
            if(s[i] == 'o'){
                if(ans[i]){
                    if(ans[n-1] != ans[1]) flag = false;
                }else{
                    if(ans[n-1] == ans[1]) flag = false;
                }
            }else{
                if(ans[i]){
                    if(ans[n-1] == ans[1]) flag = false;
                }else{
                    if(ans[n-1] != ans[1]) flag = false;
                }
            }
        }else if(i == n-1){
            if(s[i] == 'o'){
                if(ans[i]){
                    if(ans[n-2] != ans[0]) flag = false;
                }else{
                    if(ans[n-2] == ans[0]) flag = false;
                }
            }else{
                if(ans[i]){
                    if(ans[n-2] == ans[0]) flag = false;
                }else{
                    if(ans[n-2] != ans[0]) flag = false;
                }
            }
        }else{
            if(s[i] == 'o'){
                if(ans[i]){
                    if(ans[i-1] != ans[i+1]) flag = false;
                }else{
                    if(ans[i-1] == ans[i+1]) flag = false;
                }
            }else{
                if(ans[i]){
                    if(ans[i-1] == ans[i+1]) flag = false;
                }else{
                    if(ans[i-1] != ans[i+1]) flag = false;
                }
            }
        }
    }
}

void cout_ans(void){
    rep(i,n){
        if(ans[i]) cout << 'S';
        else cout << 'W';
    }
}

int main(){
    cin >> n >> s;
    // 0:羊, 1:羊
    ans[0] = 1; ans[1] = 1;
    l_search();
    if(flag){
        cout_ans();
        return 0;
    }
    // 0:羊, 1:狼
    ans[0] = 1; ans[1] = 0;
    l_search();
    if(flag){
        cout_ans();
        return 0;
    }
    // 0:狼, 1:羊
    ans[0] = 0; ans[1] = 1;
    l_search();
    if(flag){
        cout_ans();
        return 0;
    }

    // 0:狼, 1:狼
    ans[0] = 0; ans[1] = 0;
    l_search();
    if(flag){
        cout_ans();
        return 0;
    }

    cout << -1 << endl;
}