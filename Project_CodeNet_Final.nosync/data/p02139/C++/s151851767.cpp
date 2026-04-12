#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,m,c,d,top=1;
    cin>>n>>m;
    for(long long int i=0;i<m;i++){
        cin>>c>>d;
        if(top>n)top=top%n;
        if(c==0){
            if((top+d-1)%n!=0){
                cout<<(top+d-1)%n<<endl;
            }else{
                cout<<n<<endl;
            }
        }else if(c==1){
            top+=d;
        }
    }
    return 0;
}
