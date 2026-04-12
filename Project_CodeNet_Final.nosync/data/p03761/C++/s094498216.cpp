#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    vector<int> ans(26,50);
    for(int i = 0; i < n; i++){
        vector<int> check(26,0);
        for(char c : s[i]){
            check[int(c - 'a')]++;
        }
        for(int j = 0; j < 26; j++){
            if(check[j] < ans[j]) ans[j] = check[j];
        }
    }
    for(char c = 'a'; c <= 'z'; c++){
        cout << string(ans[int(c - 'a')], c);
    }
    cout << endl;
}