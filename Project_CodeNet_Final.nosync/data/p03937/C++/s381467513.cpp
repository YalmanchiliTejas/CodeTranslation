#include <bits/stdc++.h>
using namespace std;

//macro-----------------------------------------------------------------------------------------
#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long

//io_method
void print(int n){ cout << n << endl; }
int input() {int t; cin >> t; return t;}

//main------------------------------------------------------------------------------------------

struct fenwick{
    vector<int> bit;
    int s;

    fenwick(int n){
        s = n;
        rep(i,0,n+1) bit.push_back(0);
    }

    int sum(int i){
        if(i < 1) return 0;
        return bit[i] + sum(i - (i & -i));
    }

    void add(int i, int x){
        if(i > s) return; 
        bit[i] += x;
        add(i +(i & -i), x);
    }


};

signed main(){
    
    int h,w;
    cin >> h >> w;

    int ans = 0;
    rep(i,0,h){
        rep(j,0,w){
            char tmp; cin >> tmp;
            if(tmp == '#') ans++;
        }
    }

    cout << (ans == (h + w - 1) ? "Possible" : "Impossible" )<< endl;

    
    



}   