#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    long long n,x,p[64],q=0;
    cin>>n>>x;
    x--;
    p[0]=1;
    for(int i=1;i<64;i++){
        p[i]=p[i-1]*2;
    }
    for(long long i=n;i>=0;i--){
        //cout<<q<<endl;
        if(x==p[i+2]-4){
            q+=p[i+1]-1;
            i=0;
        }else if(x>=p[i+1]-2){
            q+=p[i]-1+1;
            //if(x==p[i+1]-2)q++;
            x-=p[i+1]-3+2;
        }else{
            x--;
        }
    }
    cout<<q<<endl;
}
