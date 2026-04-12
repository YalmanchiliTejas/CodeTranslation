#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define pi 3.141592653589793

ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    ll r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main (){
    int n;
    string ans;
    cin >> n;
    vector<int>alpha(26);
    rep(i,n) {
        string s;
        cin >> s;
        vector<int>al(26,0);
        rep(k,26){
            al[k]=count(s.begin(),s.end(),'a'+k);
        }
        if(i==0){
            rep(j,26){
                alpha[j]=al[j];
            }
        }
        else {
            rep(j,26) alpha[j]=min(alpha[j],al[j]);
        }
    }
    rep(i,26){
        while(alpha[i]>0){
            ans+='a'+i;
            alpha[i]--;
        }
    }
    cout << ans << endl;
    return 0;
}
