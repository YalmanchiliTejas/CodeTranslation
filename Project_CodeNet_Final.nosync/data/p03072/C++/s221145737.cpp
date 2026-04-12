#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define swap(type ,a ,b) {type t; t=a; a=b; b=t;}
#define forN(i,n) for(i=0;i<n;i++)
#define forR(i,s,n) for(i=s;i<n;i++)
#define ll long long
#define pb(t,d,n) {t p;int i;forN(i,n){cin>>p;d.push_back(p);}}

using namespace std;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;

bool cmp(pii &a, pii &b){
    return a.first < b.first;
}

int main(){
    int hmax,i,n,tmp,res;
    vi h;
    cin >> n;
    pb(int, h, n);
    hmax = 0;
    res = 0;
    forN(i,n){
        if(hmax <= h[i]){
            res++;
            hmax = h[i];
        }
    }
    cout << res << endl;
}