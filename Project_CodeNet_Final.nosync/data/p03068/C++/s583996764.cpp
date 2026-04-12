#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007 // 10^9+7
#define INF 99999999999 //10^12-1
#define P pair<int,int>
#define prique priority_queue
string s;
int n,k;
signed main(){
    cin>>n>>s>>k;
    char base=s[k-1];
    rep(i,n){
        if(s[i]==base)cout<<s[i];
        else cout<<"*";
    }
    cout<<endl;
    return 0;
}
