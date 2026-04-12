#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define ll long long
#define loop(i,n) for(int i=0; i<n; i++)
#define loop1(i,n) for(int i=1; i<=n; i++)
#define loopi(i,s,e) for(int i=s; i < e; i++)
#define loopiRev(i,s,e) for(int i=s; i >= e; i--)
#define PI 3.14159265359
//#define x first
#define y second
#define point pair<int,int>
#define len(s)   (int)s.length()
#define sz(v)    (int)v.size()
#define all(a)   a.begin(),a.end()
#define clr(x, val)	memset((x), (val), sizeof(x))

void initialize(vector<int> &F, int n){
    F = vector<int> (n+1, 0);

    for(int i=2; i*i  <= n; i++){
        if(F[i] == 0)
            for(int k=i*i; k <=n ; k+= i)
                if(F[k] == 0) F[k] = i;
    }
}

//you don't know math, unless you can do math!
vector<ll> a;

ll meme[2][3000][3000];
ll solve(int turn, int i, int j){
     if(i > j)
        return 0;

    ll &ret = meme[turn][i][j];
    if(ret != -1)
        return ret;

    if(turn){
        ll ch1 = solve(!turn, i + 1, j) - a[i];
        ll ch2 = solve(!turn, i, j - 1) - a[j];

        return ret = min(ch1, ch2);
    }
    else{
        ll ch1 = solve(!turn, i + 1, j) + a[i];
        ll ch2 = solve(!turn, i, j - 1) + a[j];

        return ret = max(ch1, ch2);
    }
}

int main() {
    //freopen("input.txt" , "r" , stdin) ;
    //freopen("output.txt" , "w" , stdout) ;

    //cin.tie(0);
    //cin.sync_with_stdio(0);

    int n; cin>>n;
    a = vector<ll> (n);

    clr(meme, -1);

    for(int i = 0; i < n; i++)
        cin>>a[i];

    cout<<solve(0, 0, n - 1);
}
