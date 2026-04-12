#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <regex>
#include <locale>
#include<set>



using namespace std;

#define MAX 300000
int main() {
    long long  h,w,i,j,halfkosu,ans,ans2;
    double a,b,c,x,y,halfvalue;
    bool flg;

    cin>>a>>b>>c>>x>>y;
    halfvalue=min((a+b)/2,c);
    halfkosu=min(x,y);

    ans=halfkosu*halfvalue*2+a*(x-halfkosu)+b*(y-halfkosu);
    ans2=halfvalue*2*max(x,y);

    ans=min(ans,ans2);
    std::cout << ans << std::endl;
    return 0;
}
