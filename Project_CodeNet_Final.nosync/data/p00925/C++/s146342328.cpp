#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back

vector<string> split(string s,char ch){
    vector<string> ret;
    string tmp ="";
    rep(i,s.size()){
        if(s[i]==ch){
            ret.pb(tmp);
            tmp = "";
        }else tmp+=s[i];
    }
    if(tmp.size())ret.pb(tmp);
    return ret;
}

int solveL(string s){
    int res = s[0]-'0';
    for(int i=1;i<s.size();i+=2){
        if(s[i]=='+')res+=s[i+1]-'0';
        if(s[i]=='*')res*=s[i+1]-'0';
    }
    return res;
}

int solveM(string s){
    vector<string> res = split(s,'+');
    
    rep(i,res.size()){
        int r = solveL(res[i]);
        stringstream ss;
        ss<<r;
        res[i] = ss.str();
    }
    int sum = 0;
    rep(i,res.size()){
        sum+=stoi(res[i]);
    }
    return sum;
}

signed main(){
    string s;
    cin>>s;
    int ans;
    cin>>ans;
    
    int m = solveM(s);
    int l = solveL(s);
    
    if(m==ans&&l==ans)cout<<'U'<<endl;
    else if(m==ans)cout<<'M'<<endl;
    else if(l==ans)cout<<'L'<<endl;
    else cout<<'I'<<endl;
    
}