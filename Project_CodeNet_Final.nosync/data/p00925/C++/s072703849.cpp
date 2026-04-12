#include <bits/stdc++.h>
using namespace std;

int calc0(string s){
    int res=0,n=s.size(),now=1;
    for (int i=0;i<n;i+=2){
        now*=s[i]-'0';
        if (i==n-1||s[i+1]=='+'){
            res+=now; now=1;
        }
    }
    return res;
}

int calc1(string s){
    int res=0,n=s.size();
    for (int i=0;i<n;i+=2){
        if (i&&s[i-1]=='*') res*=s[i]-'0';
        else res+=s[i]-'0';
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; int n; cin >> S >> n;
    int a=calc0(S),b=calc1(S);
    int m=(a==n?1:0)+(b==n?2:0);
    string result="IMLU";
    cout << result[m] << '\n';
}
