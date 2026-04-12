#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;

int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            string t;
            if(i==0) t.push_back('S');
            else t.push_back('W');
            if(j==0) t.push_back('S');
            else t.push_back('W');
            for(int k=1;k<s.length();k++){
                if(s[k]=='o'){
                    if(t[k]=='S') t.push_back(t[k-1]);
                    else{
                        if(t[k-1]=='W') t.push_back('S');
                        else t.push_back('W');
                    }
                }
                else{
                    if(t[k]=='W') t.push_back(t[k-1]);
                    else{
                        if(t[k-1]=='S') t.push_back('W');
                        else t.push_back('S');
                    }
                }
            }
            if(t[N]!=t[0]) continue;
            if(s[0]=='o'){
                if(t[0]=='S'){
                    if(t[1]!=t[N-1]) continue;
                }
                else{
                    if(t[1]==t[N-1]) continue;
                }
            }
            else{
                if(t[0]=='W'){
                    if(t[1]!=t[N-1]) continue;
                }
                else{
                    if(t[1]==t[N-1]) continue;
                }
            }
            t.pop_back();
            cout << t << endl;
            return 0;
        }
    }
    puts("-1");
    return 0;
}