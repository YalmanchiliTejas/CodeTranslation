#include<bits/stdc++.h>
using lint=long long;
using real=long double;
int main(){
    std::cin.tie(nullptr);std::ios_base::sync_with_stdio(false);
    std::cout.setf(std::ios_base::fixed);std::cout.precision(15);
    lint a,b,c,x,y;std::cin>>a>>b>>c>>x>>y;
    lint d=std::min(a+b,c+c),z=std::min(x,y);
    std::cout<<d*z+(x>y?std::min(a,c+c)*(x-z):std::min(b,c+c)*(y-z))<<'\n';
}
