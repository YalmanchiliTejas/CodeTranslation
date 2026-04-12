#include<bits/stdc++.h>
#define pi 3.141592653897932384626
#define abs(x) ((x)>0?(x):(-(x)))
#define eps (double)(0.0000001)
//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
using namespace std;
long a[105];
int main()
{
    long n,m;
    long a,b,c;
    cin>>a>>b>>c>>n>>m;
    c*=2;
    if(c>a+b){
        cout<<n*a+m*b;
    }
    else{
        if(n>m){
            cout<<min((n-m)*a+m*c,n*c);
        }
        else{
            cout<<min(n*c+(m-n)*b,m*c);
        }
    }
    cout<<endl;
    return 0;
}
