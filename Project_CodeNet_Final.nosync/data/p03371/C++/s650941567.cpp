#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define REAP(i,a,n) for(int i=(a);i<(n);i++)
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define fr first
#define sc second
#define pb push_back
#define All(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    //cout << a <<" " << y << endl;
    ll sum[10]={};
    sum[0]=2*c*max(x,y);
    sum[1]=a*x+b*y;
    if(x-y>0)sum[2]=y*2*c+(x-y)*a;
    else sum[2]=sum[0];

    if(y-x>0)sum[3]=x*2*c+(y-x)*b;
    else sum[3]=sum[0];

    ll mi=sum[0];

    REP(i,4){
        //cout << sum[i] << endl;
        if(sum[i]<0)continue;
        mi=min(sum[i],mi);
    }
    cout << mi << endl;
}
