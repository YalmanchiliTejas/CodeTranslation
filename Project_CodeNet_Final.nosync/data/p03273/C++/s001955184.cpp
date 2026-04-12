#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool Check(string s,int W){
    
    int count = 0;
    for(int i=0;i<W;i++){
        if(s[i] == '.') count++;
    }
    
    if(count == W) return false;
    else return true;
}
int main(){

    int H,W;
    cin >> H >> W;
    vector<string> S;
    string key;
    
    for(int i=0;i<H;i++){
        cin >> key;
        if(Check(key,W)) S.push_back(key);
    }
    int show_data[W];
    for(int i=0;i<W;i++) show_data[i] = 1;
    
    for(int i=0;i<W;i++){
        int count =0;
        for(int j=0;j<S.size();j++){
            if(S[j][i] == '.') count++;
        }
        if(count == S.size()) show_data[i] = 0;
    }
  
    for(int i=0;i<S.size();i++){
        for(int j=0;j<W;j++){
            if(show_data[j] == 1) cout << S[i][j]; 
        }
        cout << endl;
    }
}