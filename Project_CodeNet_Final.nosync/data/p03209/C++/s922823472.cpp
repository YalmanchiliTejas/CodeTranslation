#include <bits/stdc++.h>
using namespace std;
 
long b(long n,long x){
    if((powl(2,n+1)-2)>=x){
        if(x==0) return(0);
        else return(b(n-1,x-1));
    }
    else if((powl(2,n+1)-1)==x){
        return(powl(2,n));
    }
    else if((powl(2,n+2)-4)>=x){
        return(b(n-1,x+1-powl(2,n+1))+powl(2,n));
    }
    else return(powl(2,n+1)-1);

}
int main(void)
{
    long n,x;
    cin >> n >> x;
    cout << b(n,x);
}