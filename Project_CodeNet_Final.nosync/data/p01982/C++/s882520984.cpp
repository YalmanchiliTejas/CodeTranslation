#include <bits/stdc++.h>

int main(){
    while(true){
        int n,l,r;
        int ans=0;
        std::cin>>n>>l>>r;
        if(n==0)break;
        std::vector<int> a;
        for (int i = 0; i < n; ++i) {
            int t;
            std::cin>>t;
            a.emplace_back(t);
        }
        for (int i = l; i <= r; ++i) {
            bool f=false;
            for (int j = 1; j <= n; ++j) {
                if(j%2==1){
                    if(i%a[j-1]==0){++ans;f= true;break;}
                }
                else {
                    if(i%a[j-1]==0){f= true;break;}
                }
            }
            if(!f&&n%2==0)++ans;
        }
        std::cout<<ans<<std::endl;
    }
    return 0;
}

