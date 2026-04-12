#include<iostream>
int x,y,z,l,r,m;main(){std::cin>>x>>y>>z;r=x/y+1;while(l+1<r)m=(l+r)/2,(m*(y+z)+z>x?r:l)=m;std::cout<<l;}