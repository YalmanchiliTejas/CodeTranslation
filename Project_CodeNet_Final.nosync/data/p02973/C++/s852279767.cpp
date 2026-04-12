#include <bits/stdc++.h>
using namespace std;
multiset<int> ms;
int main(){
    int n, a, ans = 0;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a);
        auto its = ms.lower_bound(a);

        if(its != ms.begin()){
            its--;
            ms.erase(its);
        }
        else ans++;

        ms.insert(a);
    }   
    printf("%d\n", ans);
}