#include <bits/stdc++.h>
using namespace std;

int solve(){
    string s;
    cin >> s;
    if(s == "#") return 1;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    int h=0, w;
    string v;
    for(auto c : s){
        if(c=='b'){
            v.push_back(c);
        }
        if(isdigit(c)){
            int n = c-'0';
            for(int i=0;i<n;i++) v.push_back('.');
        }
        if(c=='/'){
            h++;
        }
    }
    h++;
    w = v.size()/h;
    swap(v[a*w+b], v[c*w+d]);
    string ans = "";
    int cnt = 0;
    for(int i=0;i<h;i++){
        int cnt=0;
        for(int j=0;j<w;j++){
            if(v[i*w+j]=='b'){
                if(cnt>0){
                    ans.push_back('0'+cnt);
                    cnt = 0;
                }
                ans.push_back('b');
            }
            else cnt++;
        }
        if(cnt>0) ans.push_back('0'+cnt);
        ans.push_back('/');
    }
    ans.pop_back();
    cout << ans << endl;
    return 0;
}

int main(){
    while(solve()==0);
    return 0;
}

