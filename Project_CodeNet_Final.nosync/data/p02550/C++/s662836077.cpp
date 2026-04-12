#include<bits/stdc++.h>
using namespace std;

using ll = long long;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)

int main(){
    ll N;
    int X, M;
    cin >> N >> X >> M;
    V<bool> v(M, true);
    queue<int> q;
    ll XX = X;
    while(v.at(XX)){
        q.push(XX);
        v.at(XX) = false;
        XX *= XX;
        XX %= M;
    }
    ll sum = 0;
    while(q.front() != XX && N > 0){
        sum += q.front();
        N--;
        q.pop();
    }
    ll q_sum = XX;
    q.pop();
    q.push(XX);
    while(q.front() != XX){
        int a = q.front();
        q_sum += a;
        q.pop();
        q.push(a);
    }
    sum += q_sum * (N / q.size());
    int number = N - (N / q.size()) * q.size();
    rep(i, number){
        sum += q.front();
        q.pop();
    }
    
    cout << sum << endl;
}