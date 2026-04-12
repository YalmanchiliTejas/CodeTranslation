#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    int ans=1000000001;
    int dekai=max(X,Y);

    ans = min(ans,A*X+B*Y);
    for(int i=2;(dekai-i/2)>=0;i+=2){
        if(X-i/2>=0 && Y-i/2>=0){
            ans=min(ans,A*(X-i/2)+B*(Y-i/2)+C*i);
        }else if(X-i/2<0){
            ans=min(ans,A*0+B*(Y-i/2)+C*i);
        }else if(Y-i/2<0){
            ans=min(ans,A*(X-i/2)+B*0+C*i);
        }
    }
    cout<<ans<<endl;
    return 0;
}