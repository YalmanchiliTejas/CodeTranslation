#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
typedef long long ll;
ll N, a[MAX], psum[MAX];
vector<int> val;

int main(){
    scanf("%lld", &N);
    for(int i = 1; i <= N; i++){
        scanf("%lld", a + i);
        val.push_back(a[i]);
    }
    sort(val.begin(), val.end());
    for(int i = 1; i <= N; i++){
        if(a[i] < val[(N + 1) / 2]){
            printf("%d\n", val[(N + 1) / 2]);
        }
        else
            printf("%d\n", val[(N + 1) / 2 - 1]);
    }
    return 0;
}