#include <bits/stdc++.h>

int main() {
    int n, k;
    std::string s;
    std::cin>>n;
    std::cin>>s;
    std::cin>>k;
    for(int i=0;i<n;i++){
        if(s[i]!=s[k-1]){
            s[i]='*';
        }
    }
    std::cout<<s<<std::endl;
    return 0;
}