#include<iostream>

using namespace std;

long long layer[51];

void fill_layer(long long n){
    layer[0] = 1;
    for(int i=1;i<=n;i++){
        layer[i] = layer[i-1]*2 + 3;
    }
}

long long solve(long long n, long long x){
    if(n==0){
        return 1;
    }
    else if(x==1)return 0;
    else if(x<=1+layer[n-1]){
        return solve(n-1, x-1);
    }
    else if(x==2+layer[n-1]){
        return 1+solve(n-1, layer[n-1]);
    }
    else if(x<=2+2*layer[n-1]){
        return 1+solve(n-1, layer[n-1])+solve(n-1, x-2-layer[n-1]);
    }
    else{
        return 1+solve(n-1, layer[n-1])*2;
    }
}

int main(){
    long long n, x;
    cin >> n >> x;
    fill_layer(n);
    cout << solve(n, x) << endl;
}