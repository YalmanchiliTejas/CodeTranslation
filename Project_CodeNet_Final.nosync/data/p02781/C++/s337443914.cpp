#include<bits/stdc++.h>
#define ll long long
using namespace std;
string n;
ll k, result;
map<pair<string, int>, int> save;
ll C(ll, ll);
ll solve(string, ll);
int main()
{
    save.clear();
    cin>>n>>k;
    result = solve(n, k);
    cout<<result<<"\n";
}
ll C(ll a, ll b)
{
    if(a==b) return 1;
    if(b==1) return a;
    return C(a-1, b)+C(a-1, b-1);
}
ll solve(string a, ll b)
{
    if(save.find({a, b})!=save.end()) return save[{a, b}];
    if(a.length()<b) return 0;
    while(a[0]=='0') a = a.substr(1, a.length()-1);
    if(a.length()==0) return 0;
    ll ans = 0;
    if(b==1)
        ans = 9*(a.length()-1)+a[0]-'0';
    else
    {
        string tmp = "";
        for(int i = 0; i<a.length()-1; ++i) tmp+='9';
        ans += solve(tmp, b);
        ans += solve(tmp, b-1) * (a[0]-'1');
        ans += solve(a.substr(1, a.length()-1), b-1);
    }
    return save[{a, b}] = ans;
}