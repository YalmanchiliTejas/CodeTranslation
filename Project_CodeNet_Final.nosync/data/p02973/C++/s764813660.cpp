#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int A[N],n;
multiset<int> last;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",A+i);
        auto it = last.lower_bound(A[i]);
        if(it == last.begin()){
            last.insert(A[i]);continue;
        }
        last.erase(--it);
        last.insert(A[i]);

    }
    printf("%d\n",last.size());
    return 0;
}
