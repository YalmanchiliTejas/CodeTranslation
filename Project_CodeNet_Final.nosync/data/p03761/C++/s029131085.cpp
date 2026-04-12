#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(obj) (obj).begin(),(obj).end()

string lcs(string l,string r){
    string k;
    int h=0;
    for(int i=0;i<l.size();i++){
        for(int j=h;j<r.size();j++){
            if(l[i]==r[j]){
                k.push_back(l[i]);
                h=j+1;
                break;
            }
        }
    }
    return k;
}

int main(void){
    ll n;cin>>n;
    vector<string> ss(n);
    rep(i,n)cin>>ss[i];
    rep(i,n)sort(ss[i].begin(),ss[i].end());
    string c=ss[0];
    for(int i=1;i<n;i++) c=lcs(c,ss[i]);
    cout<<c<<endl;
    return 0;
}
