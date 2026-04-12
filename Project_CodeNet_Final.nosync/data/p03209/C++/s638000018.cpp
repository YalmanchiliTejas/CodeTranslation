#include <bits/stdc++.h>
using namespace std;

int N;
typedef long long ll;
ll res=0,X;
vector<ll> v(51,1),v2(51,1);

int reg(int i,ll j){
    if (i==0 && j==1){
        res += 1;
        return 0;
    }
    else if (j==1) return 0;
    else if(j<=1+v2[i-1]){
        reg(i-1,j-1);
    }
    else if(j==1+v2[i-1]+1){
        res += v[i-1]+1;
        return 0;
    }
    else if(j<=1+v2[i-1]+1+v2[i-1]){
        res += v[i-1]+1;
        reg(i-1,j-1-v2[i-1]-1);
    }
    else if(j==3+2*v2[i-1]){
        res += 2*v[i-1]+1;
        return 0;
    }
}

int main(){
    cin >> N >> X;
    for (int i=1;i<=N;i++){
        v[i] =  2*v[i-1]+1;
        v2[i] = 3 + 2*v2[i-1];
    }

    reg(N,X);
    if (X==0)res =0;
    cout << res << endl;
    }
    //sort(v.rbegin(), v.rend(), [](auto& x, auto& y){return x[1] < y[1];});