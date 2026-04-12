#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int a,b,c,x,y;
    cin >>a>>b>>c>>x>>y;
    int sum = 0;
    if(c*2<=a+b){
        sum += c*2*min(x,y);
        if(x<=y){ // bが足りない
            sum += min(b,2*c)*(y-x);
        }
        else{     // aが足りない
            sum += min(a,2*c)*(x-y);
        }
    }
    else{
        sum = a*x + b*y;
    }

    cout << sum << endl;
    return 0;
}