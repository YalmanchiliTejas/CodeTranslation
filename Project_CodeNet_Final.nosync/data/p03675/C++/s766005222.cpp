#include<bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define pb push_back

template<typename T> bool chkmin(T&a, T b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool chkmax(T&a, T b) { return a < b ? a = b, 1 : 0; }

int N, A, B;
deque<int> Q;
int main() {

    cin >> N;
    for(int i=1; i <= N; i++) { cin >> A; if(((i&1) + (N&1))%2 == 0) Q.push_front(A); else Q.push_back(A); }

    while(!Q.empty()) { printf("%d ", Q.front()); Q.pop_front(); }
    return 0;
}
