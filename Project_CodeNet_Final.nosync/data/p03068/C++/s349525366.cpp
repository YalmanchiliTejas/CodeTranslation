#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;

int main(){
    int n, k;
    string s;
    string ans = "";
    
    cin >> n >> s >> k;
    
    for(int i = 0; i < n; i++){
        if(s[i] != s[k-1]){
            ans += "*";
        }else{
            ans += s[i];
        }
    }
    
    cout << ans << endl;
}
