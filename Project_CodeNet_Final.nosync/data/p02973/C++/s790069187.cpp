#include <cstdio>
#include <set>
using namespace std;
#define lb lower_bound
int N,ans; multiset<int> s;
int main() {
    scanf("%d",&N);
    for (int i = 0,A;i < N;i++) {
        scanf("%d",&A); set<int>::iterator it = s.lb(A);
        if (it == s.begin()) ans++;
        else it--,s.erase(it);
        s.insert(A);
    }
    printf("%d\n",ans);
}
