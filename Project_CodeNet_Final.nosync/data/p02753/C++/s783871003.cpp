#include <bits/stdc++.h>



int main()
{
    std::string s;
    int sum1=0,sum2=0;
    std::cin>>s;
    for(int i=0;i<3;i++){
        if(s[i]=='A') sum1++;
        else sum2++;
    }
    if(sum1==0 || sum2==0) std::cout<<"No"<<"\n";
    else std::cout<<"Yes"<<"\n";
    return 0;
}
