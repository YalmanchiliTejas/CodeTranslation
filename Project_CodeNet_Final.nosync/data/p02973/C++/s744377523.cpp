#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, ans, m, a;
multiset<int> ST;
multiset<int>::iterator it;

int main(){
    scanf("%d", &n);

    ans = 1;

    scanf("%d", &a);
    ST.insert(a);

    for(int i=2; i<=n; i++){
        scanf("%d", &a);
        if(a <= *ST.begin()){
            ST.insert(a);
            ans++;
        } else {
            it = ST.lower_bound(a);
            it--;
            ST.erase(it);
            ST.insert(a);
        }

    }

    printf("%d\n", ans);
	return 0;
}
