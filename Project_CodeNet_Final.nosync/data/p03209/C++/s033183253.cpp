#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define be begin
#define en end
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ALL(a) (a).be() , (a).en()
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)        //repeat n times
#define REP2(i,s,n) for(int (i)=(s);(i)<(n);(i)++)   //repeat from s to n 
#define REPD(i,n) for(int (i)=(n);(i)>=0;(i)--)      //repeat from n to 0
#define REPD2(i,s,e) for(int (i)=(s);(i)>=(e);(i)--) //repeat from s to e
#define RANGE(i,v) for(auto &(i):v)                  //repeat range
#define ASIZE(a) (sizeof(a) / sizeof(a[0]))          //array size

using LL = long long;

template<typename T> using V = vector< T >;
using Vi = V<int>;
using Vll = V<LL>;
using Vs = V<string>;

Vll a(55),p(55);
LL f(LL n, LL x){
    if(n == 0){
        return (x<=0)?0:1;
    }else if(x == 1){
        return 0;
    }else if(x <= 1 + a[n-1]){
        return f(n-1,x-1);
    }else if(x == 2+a[n-1]){
        return p[n-1]+1;
    }else if(x <= 2 + 2*a[n-1]){
        return p[n-1]+1+f(n-1,x-2-a[n-1]);
    }else if(x == 3 + 2*a[n-1]){
        return 2*p[n-1]+1;
    }
}

int main(){
    LL n,x;
    cin>>n>>x;
    a[0] = 1;
    p[0] = 1;

    REP2(i,1,n+1){
        a[i] = 2*a[i-1] + 3;
        p[i] = 2*p[i-1] + 1;
    }

    cout<<f(n,x)<<endl;

    return 0;
}