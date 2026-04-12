#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    //普通に買う場合
    long long int sum_normal;
    sum_normal=x*a+y*b;
    //ABピザを使う場合
    long long int sum_AB;
    if (x==y) {
        sum_AB=c*x*2;
    } else if (x<y) {
        sum_AB=min(c*x*2+b*(y-x),c*y*2);
    } else {
        sum_AB=min(c*y*2+a*(x-y),c*x*2);
    }
    cout<<min(sum_normal,sum_AB)<<endl;
}
