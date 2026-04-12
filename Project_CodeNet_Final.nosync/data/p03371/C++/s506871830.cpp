#include <bits/stdc++.h>
typedef  long long ll;
#define INF 1000000000
#define N 100005
using namespace std;
int main(void){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int ans=INF;
    for(int i=0;i<=max(2*x,2*y);i+=2){
        int tmp=0,num_x,num_y;
        num_x=(x-i/2);
        num_y=(y-i/2);
        if(num_x<0){
            num_x=0;
        }
        if(num_y<0){
            num_y=0;
        }
        tmp=num_x*a+num_y*b+i*c;
        if(tmp<ans){
            ans=tmp;
        }

    }
    cout<<ans<<endl;

}