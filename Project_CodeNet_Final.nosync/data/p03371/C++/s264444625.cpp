#include <bits/stdc++.h>

using namespace std;
using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const ll inf = 1e9+7;
const ll mod = 1e9+7;

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    int sum=0;

    if(a+b<2*c)sum=a*x+b*y;
    else{
        sum+=2*c*min(x,y);
        if(x>y)sum+=(x-y)*min(a,c*2);
        else sum+=(y-x)*min(b,c*2);
    }

    cout<<sum<<endl;
}

