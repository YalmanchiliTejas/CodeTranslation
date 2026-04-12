// In The Name Of God
#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define int long long
#define ll long long
#define for2(a,b,c) for(int (a) = (b); (a) < (c); (a)++)
#define setp cout << fixed << setprecision(15)
#define endl "\n"
#define minit(a,b) a = min(a,b)
#define maxit(a,b) a = max(a,b)
#define PII pair<int,int>
#define Vec vector<int>
#define error(x) cerr << #x << " = " << (x) << endl;
#define all(x) (x).begin() , (x).end()



int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> v;
    int n; cin >> n;
    vector<int> a(n);
    for2(i,0,n) cin >> a[i],v.pb(a[i]);
    sort(all(v));
    int med = (n-1)/2;
    for2(i,0,n){
        if(v[med] >= a[i]) cout << v[med+1] << endl;
        else cout << v[med] << endl;
    }
    return 0;
}
