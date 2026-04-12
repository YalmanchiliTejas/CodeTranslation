#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int , int> P;
typedef pair<ll, ll> PL;
const ll MOD = 1E9+7;
 
ll maxll(ll a, ll b){
    if(a >= b)  return a;
    else    return b;
}

bool SecondCompare(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}
 
bool SecondCompareDes(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second>b.second;
}

ll n;
ll x[200000+10], a[200000+10];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        a[i] = x[i];
    }
    sort(x, x+n);
    ll mid = x[n/2];
    for(int i = 0; i < n; i++){
        if(a[i] < x[n/2]){
            cout << x[n/2] << endl; 
        }
        else{
            cout << x[n/2-1] << endl;
        }
    }
}