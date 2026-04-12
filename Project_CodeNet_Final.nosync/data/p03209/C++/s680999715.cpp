#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<limits>
#include<iomanip>
#include<cmath>
#include<climits>
using namespace std;

typedef long long ll;
typedef string S;
typedef pair<int,int> P;
typedef vector<int> vi;
const int mod=1e9+7;


ll numP(ll n){
    if(n==0){
        return 1;
    }else{
        return 2*numP(n-1)+1;
    }
}
ll len(ll n){
    if(n==0){
        return 1;
    }else{
        return 2*len(n-1)+3;
    }
}
ll ans=0;

ll dfs(ll n,ll x){
    if(n==0){
        return 1;
    }
    if(x<=len(n)/2&&x!=1){
        return dfs(n-1,x-1);
    }else if(x==1+len(n)/2){
        return numP(n-1)+1;
    }else if(x>1+len(n)/2&&x!=len(n)){
        return numP(n-1)+1+dfs(n-1,x-len(n)/2-1);
    }else if(x==1){
        return 0;
    }else if(x==len(n)){
        return numP(n-1)*2+1;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,x;
    cin >> n >> x;
    /*
    for(ll i=0;i<=n;i++){
        cout << i << " " << numP(i) << " " << len(i) << endl;
    }
    */
    cout << dfs(n,x) << endl;
    return 0;
}