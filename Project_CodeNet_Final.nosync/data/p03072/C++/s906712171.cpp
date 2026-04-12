#include <bits/stdc++.h>

int main() {
    int n,temp;
    int ans=0;
    std::vector<int> v;
    std::cin>>n;
    for(int i=0;i<n;i++) {
        std::cin >> temp;
        v.push_back(temp);
    }
    for(int i=0;i<n;i++){
        int f=0;
        for(int j=0;j<i;j++){
            if(v[i]>=v[j]){
                continue;
            }
            else{
                f++;
            }
        }
        if(f==0){
            ans = ans+1;
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}