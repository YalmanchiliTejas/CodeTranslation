#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<ctime>
#include<cmath>
#include<utility>
#include<cstdlib>
#include<bitset>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
using namespace std;                       

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const ll M = 1e9 + 7;

ll add(ll a, ll b){
    (a += b)%=M;
    (a += M)%=M;
    return a;
}

ll mul(ll a, ll b){
    (a *= b)%=M;
    (a += M)%=M;
    return a;
}

ll fastpo(ll a, ll x){
    if(x == 0) return 1ll;
    if(x == 1) return a;
    ll y = fastpo(a, x/2);
    if(x%2 == 0){
        return y*y;
    }
    return y*y*a;
}

ll inv(ll a, ll M){
    return fastpo(a, M-2);
}

ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}

ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        return -1; 
    else
    { 
        ll res = (x%m + m) % m; 
        return res;
    } 
}


ll gcd(ll a, ll b){
    if(a == 0){
        return b;
    }
    return gcd(b%a, a);
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a, b);
}

void print(vector<int> &a){
    int n = a.size();
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}



int main(){
//    clock_t time_req;
//     time_req = clock();
    fastio;
    int x;
    cin>>x;
    if(x >= 30) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    // print(cost);
    // print(cost1);
    // time_req = clock()-time_req;
    // cout<<"Time taken: "<<(float)time_req/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}