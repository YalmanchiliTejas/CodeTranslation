#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(x) begin(x),end(x)
#include <bits/stdc++.h>
#define pll pair<ll,ll>
#define vi vector<int>
#define ld long double
#define ll long long
#define pb push_back
#define mid (l+r)/2
#define S second
#define F first
using namespace std;
string s;
int main(){
    fast,cin>>s;
    int A = 0,B = 0;
    for(int i=0;i<s.size();i++){
        A += (s[i] == 'A');
        B += (s[i] == 'B');
    }
    if(!A || !B) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
