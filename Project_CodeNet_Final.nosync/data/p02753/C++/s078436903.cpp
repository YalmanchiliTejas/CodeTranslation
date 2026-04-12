#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main(){
    fast_io

    string s;
    cin>>s;

    if(s[0]==s[1] && s[1]==s[2]){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }

    return 0;
}