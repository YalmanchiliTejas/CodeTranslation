#include <iostream>
using namespace std;

long long a[55], p[55];//a:暑さ、p:パティ

long long burger(int n, long long x){
    if(n==0){
        return x <= 0 ? 0 : 1;
    }else if(x <= 1 + a[n-1]){
        return burger(n-1, x-1);
    }else{
        return p[n-1] + 1 + burger(n - 1, x - 2 - a[n-1]);
    }
}

int main(){
    int n;
    long long x;
    cin >> n >> x;
    a[0] = 1;
    p[0] = 1;
    for(int i = 1; i <= n; i++){
        a[i] = a[i-1] * 2 + 3;
        p[i] = p[i-1] * 2 + 1;
    }

    cout << burger(n, x) << endl;
    return 0;
}