#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<string> ans(4);
    s += s.substr(0,2);
    string x1,x2;
    for(int i=1; i<n+1; i++){
        if(s[i-1]=='o'){
            if(i==1){
                ans[0] += "WSW";
                ans[1] += "SSS";
                ans[2] += "SWW";
                ans[3] += "WWS";
            }else{
                for(int j=0; j<4; j++){
                    x1 = ans[j][i-1];
                    x2 = ans[j][i];
                    if(x1==x2){
                        ans[j] += "S";
                    }else{
                        ans[j] += "W";
                    }
                    
                }
            }
        }else{
            if(i==1){
                ans[0] += "SSW";
                ans[1] += "WSS";
                ans[2] += "SWS";
                ans[3] += "WWW";
            }else{
                for(int j=0; j<4; j++){
                    x1 = ans[j][i-1];
                    x2 = ans[j][i];
                    if(x1==x2){
                        ans[j] += "W";
                    }else{
                        ans[j] += "S";
                    }
                    
                }
            }

        }
    }
    for(int i=0; i<4; i++){
        if(ans[i].substr(0,2) == ans[i].substr(n,n+1)){
            cout << ans[i].substr(1,n) << endl;
            exit(0);
        }
    }
    cout << -1 << endl;
}