#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    double x=1.00000000/a;
    double y=1.00000000/b;
    double z=x+y;
    double ans=1/z;
    printf("%.8lf",ans);
    cout<<endl;
    return 0;
}