#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,l,r,a;
    while (cin>>n>>l>>r) {
        if (n==0&&l==0&&r==0) {
            break;
        } else {
            int ans=0;
            std::deque<int> deq;
            for (int i=1;i<=n;i++) {
                cin>>a;
                deq[i]=a;
            }
            for (int j=l;j<=r;j++) {
                int flag=0;
                for (int k=1;k<=n;k++) {
                    if (j%deq[k]==0) {
                        if (k%2==1) {
                            ans++;
                        }
                        flag=1;
                        break;
                    }
                }
                if (flag==0) {
                    if (n%2==0) {
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
}
