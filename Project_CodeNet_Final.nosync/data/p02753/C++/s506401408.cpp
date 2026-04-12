#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep_1(i,n) for(int (i)=0;(i)<=(n);(i)++)
#define rep_2(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main(){
    string s;cin>>s;
    int a = 0;
    int b = 0;
    rep(i,3){
        if(s[i] == 'A' )a++;
        if(s[i] == 'B' )b++;
    }
    if(a==3 || b == 3)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;


    return 0;
}

