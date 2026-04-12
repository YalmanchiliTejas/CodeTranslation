#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int main(){
    string s;cin>>s;
    if(s[0]!=s[1] || s[1]!=s[2] || s[2]!=s[0]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}