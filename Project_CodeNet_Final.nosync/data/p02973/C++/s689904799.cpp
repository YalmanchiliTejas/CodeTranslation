#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,x,n) for(int i=(x);i<(n);i++)
#define sortn(a) sort(a.begin(),a.end())
#define sortr(a) sort(a.begin(),a.end(),greater<int>())
#define INT_MAX 2147483647
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
 
int main(){
    
    int n;
    cin >> n;
    vi a(n);
    rep(i,n){
        cin >> a[i];
        a[i] = -a[i];
    }
    int c=0;
    vi p;
    vi::iterator itr;
 
    rep(i,n){
        itr = upper_bound(p.begin(),p.end(),a[i]);
        if(itr != p.end()){
            *itr = a[i];
        }else{
            p.push_back(a[i]);
            c++;
        }
    }
 
    cout << c << endl;
    
    return 0;
}