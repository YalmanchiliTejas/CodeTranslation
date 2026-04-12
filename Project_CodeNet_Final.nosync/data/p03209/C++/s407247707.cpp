#include <bits/stdc++.h>
using namespace std;

vector<long long> burger, patty;

long long f(long long N, long long X){
    if(N == 0){
        if(X <= 0) return 0;
        else return 1;
    }else if(X <= 1 + burger[N - 1]){
        return f(N - 1, X - 1);
    }else{
        return patty[N - 1] + 1 + f(N - 1, X - 2 - burger[N - 1]);
    }
}

int main(){

    long long N, X;
    cin >> N >> X;

    burger.push_back(1), patty.push_back(1);
    for(int i = 0; i < N; i++){
        burger.push_back(2 * burger[i] + 3);
        patty.push_back(2 * patty[i] + 1);
    }

    cout << f(N, X) << endl;

    return 0;
}

