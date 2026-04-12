#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int n;
string s, ans;
char ani[200000], S = 'S', W = 'W';

bool solve(){
    bool res = true;
    for (int i = 1; i < s.size() - 2; i++){
        if (ani[i] == S && s[i] == 'o') ani[i + 1] = ani[i - 1];
        else if (ani[i] == W && s[i] == 'x') ani[i + 1] = ani[i - 1];
        else {
            if (ani[i - 1] == S) ani[i + 1] = W;
            else ani[i + 1] = S;
        }
    }
    int right;
    for (int i = 1; i < n; i++){
        if (i != n - 1) right = i + 1;
        else right = 0;
        if (ani[i] == S){
            if (s[i] == 'o' && ani[right] != ani[i - 1]) res = false;
            else if (s[i] == 'x' && ani[right] == ani[i - 1]) res = false;
        }else{
            if (s[i] == 'x' && ani[right] != ani[i - 1]) res = false;
            else if (s[i] == 'o' && ani[right] == ani[i - 1]) res = false;
        }
    }
    return res;
}

int main(){
    sc(n)
    cin >> s;
    bool check = false;
    for (int i = 0; i < 4; i++){
        if (i == 0){
            ani[0] = S;
            ani[1] = S;
            if (s[0] == 'o') ani[n - 1] = S;
            else ani[n - 1] = W;
        }else if (i == 1){
            ani[0] = S;
            ani[1] = W;
            if (s[0] == 'o') ani[n - 1] = W;
            else ani[n - 1] = S;
        }else if (i == 2){
            ani[0] = W;
            ani[1] = W;
            if (s[0] == 'o') ani[n - 1] = S;
            else ani[n - 1] = W;
        }else {
            ani[0] = W;
            ani[1] = S;
            if (s[0] == 'o') ani[n - 1] = W;
            else ani[n - 1] = S;
        }
        if (solve()){
            check = true;
            break;
        }
    }
    for (int i = 0; i < n; i++) ans += ani[i];
    if (check) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}