//
//  main.cpp
//  cell distance
//
//  Created by Dong Truong on 5/28/19.
//  Copyright © 2019 Dong Truong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
#define cmod 1000000007
#define maxn 1000001

int64_t n,m,k,sl;
int64_t pow(int64_t a,int64_t n)
{
    if (n==0) return 1;
    int64_t t=pow(a,n/2);
    t=(t*t)%cmod;
    if (n%2==1) return (t*a)%cmod;
    return t;
}
void pre()
{
    int64_t o=1;
    for (int i=1;i<=n*m-2;++i)
        o=(o*i) %cmod;
    int64_t u=1;
    for (int i=1;i<=k-2;++i)
        u=(u*i) %cmod;
    int64_t v=1;
    for (int i=1;i<=n*m-k;++i)
        v=(v*i) %cmod;
    u=(u*v)%cmod;
    if (k-2<=0 || n*m-k<=0) sl=1;
    else
        sl=(o*pow(u,cmod-2)) % cmod;
}
void sol()
{
    int64_t kq=0;
    for (int i=1;i<=n-1;++i)
    {
        int64_t o=( (i*sl) % cmod * (m*m) % cmod ) %cmod;
        kq=( kq+( (n-i) * o ) % cmod ) % cmod;
        //kq=(kq+o)%cmod;
    }
    for (int i=1;i<=m-1;++i)
    {
        int64_t o=( (i*sl) % cmod * (n*n) %cmod ) % cmod;
        kq=(kq+((m-i)*o)%cmod)%cmod;
        //kq=(kq+o)%cmod;
    }
    cout<<kq;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    //freopen("a.inp","r",stdin);
    cin>>n>>m>>k;
    pre();
    sol();
    return 0;
}
