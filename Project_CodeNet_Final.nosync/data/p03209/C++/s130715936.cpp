#include <bits/stdc++.h>

using namespace std;

vector<long long> burger_size;
vector<long long> patty;

long long solve(long long level, long long eaten){

    //printf("%lld %lld %lld %lld \n", level, eaten, burger_size[level], patty[level]);

    if(eaten == 0){
        return 0;
    }

    if(eaten == burger_size[level])
        return patty[level];

    if(eaten  < burger_size[level] / 2 + 1){

        return solve(level - 1, eaten - 1);

    } else if(eaten == burger_size[level] / 2 + 1){

        return 1 + patty[level - 1];

    } else if(eaten > burger_size[level] / 2 + 1){

        return 1 + patty[level - 1] + solve(level - 1, eaten - 2 - burger_size[level - 1]);

    }
}

int main(){
    long long n, x;
    scanf("%lld %lld", &n, &x);

    burger_size.push_back(1);

    for(int i = 1; i <= n; i++){
        burger_size.push_back(burger_size[i - 1] * 2ll + 3);
    }

    patty.push_back(1);

    for(int i = 1; i <= n; i++){
        patty.push_back(patty[i - 1] * 2ll + 1);
    }

    //printf("%lld", burger_size[n]);
    long long ans = solve(n, x);
    printf("%lld", ans);
}
