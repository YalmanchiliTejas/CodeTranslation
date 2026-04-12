#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> ss(n);
    for(int i = 0; i < n;i++){
        cin >> ss[i];
    }
    
    string ans;
    for(char c ='a';c<='z';c++){
        int num = 100;
        for(int i = 0; i < n;i++){
            int cnt = 0;
            for(auto j : ss[i]){
                if(j == c)cnt++;
            }
            
            num = min(num,cnt);
            
        }
        ans += string(num,c);
    }
    cout << ans << '\n';
    return 0;
    
    
    
    
    
}