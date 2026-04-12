#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;


vector<ll> num;
vector<ll> numP;

ll np(ll x, ll n){
    
    if (n == 0) {
        return 1;
    }else{
        
        if (x == 1) {
            return 0;
        }else if(x >= 2 && x <= num[n-1]+1){
            return np(x-1, n-1);
        }else if(x == num[n-1]+2){
            return numP[n-1]+1;
        }else if(x >= num[n-1]+3 && x <= num[n-1]*2+2){
            return np(x-(num[n-1]+1), n) + numP[n-1] + 1;
        }else{
            return numP[n];
        }
        
    }
    
    
    
    
    
    
}



int main()
{
    ll N,X;
    cin >> N >> X;
    ll a = 1;
    ll b = 1;
    num.push_back(a);
    numP.push_back(b);
    for (int i = 1; i < N+1; i++) {
        a = 3 + a*2;
        b = 2*b + 1;
        num.push_back(a);
        numP.push_back(b);
    }
    
    
    cout << np(X,N) << endl;
    
    
    return 0;
}

