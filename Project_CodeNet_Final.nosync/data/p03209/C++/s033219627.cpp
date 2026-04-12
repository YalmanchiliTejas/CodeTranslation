#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(a) (a).begin(),(a).end()
 
int main(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> p(n+1), b(n+1);
    p[0] = 1;
    b[0] = 0;
    string bar = "|";
    for(int i =1; i <= n; i++){
       p[i] = p[i-1]*2 + 1;
       b[i] = b[i-1]*2 + 2;
       //bar = "0" + bar + "|" + bar + "0";
       //cout << "level" << i << ":" << bar << endl;
    }


    int i = 1;
    ll res = 0;
    ll start = 1;
    if(x > (p[n]+b[n])/2){
        res += p[n-1]+1;
        start += (p[n]+b[n])/2;
        //cout << "av:" << res << "& start" << start << endl;
    }
    while(i <= n && start <= x){
        if(p[n-i]+b[n-i] + start <= x){
            res += p[n-i];
            start += p[n-i] + b[n-i];
            if(start == x || start >= p[n]+b[n] - n)break;
            res++;
            start++;
            if(i==n && start < x){
                res++;
                start++;
            }
            //cout << "in:" << n-i << "&" << start <<endl;
        }
        if(start == x)break;
        i++;
        start++;
    }
    //cout << start << endl;
    cout << res << endl;
    //rep(i, n+1)cout << "p:" << p[i] << "b:" << b[i] << endl;
 }