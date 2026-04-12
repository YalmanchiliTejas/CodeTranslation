#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long> p(51, 0), l(51, 0);

unsigned long func(int n, unsigned long x){
    if(n == 0) return 1;
    if(x == 1){
        return 0;
    }else if(x <= 1 + l[n-1]){
        return func(n-1, x-1);
    }else if(x == 1 + l[n-1] + 1){
        return p[n-1] + 1;
    }else if(x <= 1 + l[n-1] + 1 + l[n-1]){
        return p[n-1] + 1 + func(n-1, x - 1 - l[n-1] - 1);
    }else if(x == 1 + l[n-1] + 1 + l[n-1] + 1){
        return p[n-1] + 1 + p[n-1];
    }
    return 0;
}

int main(){
    int N;
    unsigned long X;
    cin>>N>>X;

    p[0] = 1;
    for(int i=1; i<=N; ++i){
        p[i] = p[i-1] + 1 + p[i-1];
    }
    l[0] = 1;
    for(int i=1; i<=N; ++i){
        l[i] = 1 + l[i-1] + 1 + l[i-1] + 1;
    }

    unsigned long ans = func(N, X);
    cout<<ans<<endl;

    return 0;
}

