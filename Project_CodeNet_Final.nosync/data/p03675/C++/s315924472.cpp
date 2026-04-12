#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, a[N];
deque<int> dq;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
        if(i & 1) dq.push_back(i);
        else dq.push_front(i);
    }
    for(int i = 1; i <= n; i++){
        if(n & 1){
            printf("%d ", a[dq.back()]);
            dq.pop_back();
        }
        else{
            printf("%d ", a[dq.front()]);
            dq.pop_front();
        }
    }
}