#include <bits/stdc++.h>
using namespace std;

long long int N, a[364364], i;
vector<long long> b, c;

int main(){
    scanf("%lld", &N);
    for(; i < N; ++i)scanf("%lld", a + i);
    for(i = 0; i < N; ++i){
        if(i % 2){
            b.push_back(a[i]);
        }else{
            c.push_back(a[i]);
        }
    }
    if(N % 2){
        for(auto beg = c.rbegin(), edn = c.rend(); beg != edn; ++beg){
            cout << *beg << " ";
        }
        for(auto beg = b.begin(), edn = b.end(); beg != edn; ++beg){
            cout << *beg << " ";
        }
    }else{
        for(auto beg = b.rbegin(), edn = b.rend(); beg != edn; ++beg){
            cout << *beg << " ";
        }
        for(auto beg = c.begin(), edn = c.end(); beg != edn; ++beg){
            cout << *beg << " ";
        }
    }
    return 0;
}
