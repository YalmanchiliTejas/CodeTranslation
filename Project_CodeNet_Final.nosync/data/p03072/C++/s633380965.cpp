/*
 * Created by: Son Dinh
 */ 
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(X) (int)(X).size()
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int mod=1e9+7;

int n,h,res,mx;
int main(){
    cin>>n>>h;
    mx=h;
    res=1;
    for(int i=2;i<=n;++i){
        cin>>h;
        if(h>=mx) res++;
        mx=max(h,mx);
    }
    cout<<res;
    return 0;
}

