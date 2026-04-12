#include <bits/stdc++.h>
using namespace std;
int N, A[200002];
vector<int> vt;
int main(){
    scanf("%d", &N);
    deque<int> dq;
    for(int i = 0; i < N; i++){
        scanf("%d", A + i);
        if(i & 1)dq.push_back(A[i]);
        else dq.push_front(A[i]);
    }
    if(N % 2 == 0)reverse(dq.begin(), dq.end());
    for(auto &i : dq)
        printf("%d ", i);
    return 0;
}
