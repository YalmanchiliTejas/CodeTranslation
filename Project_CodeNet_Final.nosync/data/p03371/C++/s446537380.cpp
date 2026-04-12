#include<bits/stdc++.h>

int main()
{
    int a,b,c,x,y;
    std::cin>>a>>b>>c>>x>>y;

    c *= 2;
    int res1 = a*x + b*y;
    int res2 = std::min(x,y) * c;
    if(x < y){
        res2 += (y - x) * b;
    }
    if(x > y){
        res2 += (x - y) * a;
    }
    int res3 = std::max(x,y) * c;
    res2 = std::min(res2,res3);
    std::cout<<std::min(res1,res2)<<std::endl;
    return 0;
}