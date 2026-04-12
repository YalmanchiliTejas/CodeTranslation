#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;

const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;

bool SecondCompare(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}
 
bool SecondCompareDes(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second>b.second;
}

ll minll(ll a, ll b){
    if(a >= b)  return b;
    else    return a;
}

ll maxll(ll a, ll b){
    if(a >= b)  return a;
    else    return b;
}

ll gcd(ll a, ll b){
    ll tmp;
    if(a%b == 0){
        return b;
    }
    else{
        return gcd(b, a%b);
    }
}

const ll SIZE = 1e5+10;

string s;

int main(){
    cin >> s;
    for(int i = 1; i <= 2; i++){
        if(s[i] != s[0]){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}