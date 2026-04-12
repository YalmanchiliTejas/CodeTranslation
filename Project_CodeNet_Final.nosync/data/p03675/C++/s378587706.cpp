#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;
deque<int> dq;

int main() {
    scanf("%d", &N);
    arr.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    bool l = (N % 2);
    for(int i = 0; i < N; i++) {
        if(l) dq.push_front(arr[i]);
        else dq.push_back(arr[i]);
        l ^= 1;
    }

    for(int i = 0; i < N; i++) {
        printf("%d ", dq.front());
        dq.pop_front();
    }
}
