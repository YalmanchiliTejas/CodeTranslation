#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <queue>
#include <cctype>
#include <climits>
#include <stack>
#include <map>
#include <cstring>
#include <cassert>
 
using namespace std;

int main(){

    long long n,k;
    cin>>n>>k;

    long long res=0;
    for(long long b=1;b<=n;b++){
        long long r=n%b,p=(n-r)/b; //n=pb+r
        res+=p*max(0LL,b-k)+max(0LL,r-k+1LL);
        if(k==0) res--; // a=0
    }
    cout<<res<<endl;

}
