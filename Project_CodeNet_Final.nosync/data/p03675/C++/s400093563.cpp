#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, x;
deque <int> q;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n ; ++i){
        scanf("%d", &x);
        if(i % 2 == 0) q.push_front(x);
        else q.push_back(x);
    }
    if(n % 2 == 0){
        while(!q.empty()){
            printf("%d ", q.front());
            q.pop_front();
        }
    }
    else{
        while(!q.empty()){
            printf("%d ", q.back());
            q.pop_back();
        }

    }
    return 0;
}
