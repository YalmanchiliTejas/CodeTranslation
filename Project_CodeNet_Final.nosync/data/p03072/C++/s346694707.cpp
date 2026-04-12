#include <bits/stdc++.h>
using namespace std;
int A[100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++ ) {
        scanf("%d",&A[i]);
    }
    int H = A[1];
    int ans = 1;
    for(int i=2;i<=n;i++) {
        if(A[i] >= H) {
            ans += 1;
            H = A[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
