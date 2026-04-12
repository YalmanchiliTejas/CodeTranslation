#include "bits/stdc++.h"
using namespace std;
deque<int> fff;
int main(){
    bool push_b = true;
    int n; scanf("%d", &n);
    for(int e = 0; e < n; e++){
        int x; scanf("%d", &x);
        if(push_b) fff.push_back(x);
        else fff.push_front(x);
        push_b = !push_b;
    }
    vector<int> ans;
    if(push_b){
        while(!fff.empty()){
            ans.push_back(fff.front());
            fff.pop_front();
        }
    } else {
        while(!fff.empty()){
            ans.push_back(fff.back());
            fff.pop_back();
        }
    }
    for(int e = 0; e < n; e++)
        printf("%d ", ans[e]);
    printf("\n");
    return 0;
}
