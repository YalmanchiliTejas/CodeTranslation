#include <bits/stdc++.h>
#define rep(i,a) for(int i=0;i<int(a);++i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using ll = long long;
using itn = int;
using namespace std;
using Graph = vector<vector<int>>;
static const long double GRATIO=(long double)(1+sqrt(5))/2;
ll GCD(ll a, ll b){
    return b ? GCD(b, a%b) : a;
}
ll LCM(ll a, ll b){
    return a/GCD(a,b)*b;
}
int main(){
    int H,W;
    cin>>H>>W;
    vector<vector<char>> A(H,vector<char>(W));
    int cnt=0;
    rep(i,H){
        rep(j,W){
            cin>>A[i][j];
            if(A[i][j]=='#') cnt++;
        }
    }
    if(cnt==H+W-1){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }

}