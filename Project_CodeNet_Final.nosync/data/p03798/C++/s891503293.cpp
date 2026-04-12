#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    string s;
    cin >> n >> s;
    for(ll i=0;i<2;i++){
        for(ll j=0;j<2;j++){
            string t="";
            if(i==0) t+='S';
            else t+='W';
            if(j==0) t+='S';
            else t+='W';
            for(ll k=1;k<n-1;k++){
                if(s[k]=='o'&&t[k]=='S'&&t[k-1]=='S') t+='S';
                else if(s[k]=='o'&&t[k]=='S'&&t[k-1]=='W') t+='W';
                else if(s[k]=='o'&&t[k]=='W'&&t[k-1]=='S') t+='W';
                else if(s[k]=='o'&&t[k]=='W'&&t[k-1]=='W') t+='S';
                else if(s[k]=='x'&&t[k]=='S'&&t[k-1]=='S') t+='W';
                else if(s[k]=='x'&&t[k]=='S'&&t[k-1]=='W') t+='S';
                else if(s[k]=='x'&&t[k]=='W'&&t[k-1]=='W') t+='W';
                else if(s[k]=='x'&&t[k]=='W'&&t[k-1]=='S') t+='S';
            }
            bool flag=true;
            if(t[0]=='S'&&s[0]=='o'&&t[1]!=t[n-1]) flag=false;
            else if(t[0]=='S'&&s[0]=='x'&&t[1]==t[n-1]) flag=false;
            else if(t[0]=='W'&&s[0]=='o'&&t[1]==t[n-1]) flag=false;
            else if(t[0]=='W'&&s[0]=='x'&&t[1]!=t[n-1]) flag=false;
            for(ll k=1;k<n-1;k++){
                if(t[k]=='S'&&s[k]=='o'&&t[k-1]!=t[k+1]) flag=false;
                else if(t[k]=='S'&&s[k]=='x'&&t[k-1]==t[k+1]) flag=false;
                else if(t[k]=='W'&&s[k]=='o'&&t[k-1]==t[k+1]) flag=false;
                else if(t[k]=='W'&&s[k]=='x'&&t[k-1]!=t[k+1]) flag=false;
            }
            if(t[n-1]=='S'&&s[n-1]=='o'&&t[0]!=t[n-2]) flag=false;
            else if(t[n-1]=='S'&&s[n-1]=='x'&&t[0]==t[n-2]) flag=false;
            else if(t[n-1]=='W'&&s[n-1]=='o'&&t[0]==t[n-2]) flag=false;
            else if(t[n-1]=='W'&&s[n-1]=='x'&&t[0]!=t[n-2]) flag=false;
            if(flag){
                cout << t << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
