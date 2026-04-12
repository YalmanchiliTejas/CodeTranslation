#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<((a*100+b*10+c)%4==0?"YES\n":"NO\n");
    return 0;
}