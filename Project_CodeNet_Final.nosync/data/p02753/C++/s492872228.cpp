#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxs = 1e6+5;
const ll lmaxs = 20;
ll mod = 1e9+7;
ll oo = 1e9;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int main(){
    //freopen("input00.txt","r",stdin);
    ll T = 1;
    //cin>>T;
    while(T--){
         ll n,m;
         string s;
         cin>>s;
         map<char , ll> MAP;
         for(ll i=0;i<s.size();i++)
            MAP[s[i]]++;
        if(MAP.find('B') != MAP.end() and MAP.find('A') != MAP.end())
            cout << "Yes";
        else
            cout << "No";
        
    }
    return 0;
}