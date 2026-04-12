#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MAX_N = 101010;
int f[MAX_N];

int Bin(int x, int l, int r){
    if(x<=f[r]){
        return r+1;
    }
    if(f[l]<x){
        return l;
    }
    int mid = (l+r+1)/2;
    if(l+1==r){
        return r;
    }
    if(f[mid]<x){
        return Bin(x,l,mid);
    }else{
        return Bin(x,mid,r);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i,n){
        cin >> a[i];
    }

    int ans = 0;

    rep(i,n){
        f[i] = -1;
    }

    rep(i,n){
        //cout << i << ans << endl;
        if(ans==0){
            f[ans] = a[i];
            ans++;
        }else{
            int j = Bin(a[i],0,ans-1);
            if(j==ans){
                f[ans] = a[i];
                ans++;
            }else{
                f[j] = a[i];
            }
        }
    }

    

    cout << ans << endl;
    return 0;
}
 
 
