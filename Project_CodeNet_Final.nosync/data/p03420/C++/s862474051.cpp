//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define int long long

#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int mod = 1e9 + 7;
const int N   = 2e5 + 5;

int n,k,i,j,ans;

signed main(){
    cin >> n >> k;
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j+=i){
            ans += max(0LL , min(n-j+1,i)-k);
        }

    }
    cout << ans + (n-k) * (n-k+1) / 2 - n*(k==0);
    return 0;
}