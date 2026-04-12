#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const auto INF = (ll)1e9;
using v = vector<ll>;
using p = pair<ll,ll>;
using m = map<ll,ll>;
using vv = vector<v>;
int gcd(int a,int b){
    return a==0? b :gcd(a,a%b);
}


int main(){
    ll n;
    cin >> n;
    auto c = vector<v>(n,v('z'-'a'+1,0));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            c[i][s[j]-'a']++;
        }
    }
    
    string s;
    for (int i = 0; i < 'z'-'a'+1; i++)
    {
        bool f=true;
        ll _min = INF;
        for (int j = 0; j < n; j++)
        {
            _min = min(_min,c[j][i]);
        }
      
        for (int j = 0; j < _min; j++)
        {
            s.push_back('a'+i);
        }
    }
    cout << s;
}  
