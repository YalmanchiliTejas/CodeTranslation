#include<bits/stdc++.h>
using namespace std;

const int SIZE = 200005;
int N;
map<pair<int, int>, long long> m;

int main(){
    cin >> N;
    long long A[SIZE];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    for (int i = 1; i <= N; i+=2)
        m[make_pair(i, i/2 + 1)] = m[make_pair(i-2, i/2)] + A[N-i];

    for (int i = 2; i <= N; i+=2){
        long long larger = max(A[N-i], A[N-i+1]);
        m[make_pair(i, i/2)] = max(m[make_pair(i-2, (i-2)/2)]+A[N-i], m[make_pair(i-3, (i-2)/2)]+larger);
    }

    for (int i = 3; i <= N; i+=2){
        m[make_pair(i, i/2)] = m[make_pair(i-2, i/2 - 1)] + A[N-i];
        m[make_pair(i, i/2)] = max(m[make_pair(i, i/2)], m[make_pair(i-3, i/2 - 1)] + A[N-i+1]);
        m[make_pair(i, i/2)] = max(m[make_pair(i, i/2)], m[make_pair(i-4, i/2 - 1)] + A[N-i+2]);
    }

    cout << m[make_pair(N, N/2)] << endl;
}