#include<iostream>
using namespace std;
int a,b,cnt;
char c;
main(){
    cin>>a>>b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>c;
            if(c=='#')cnt++;
        }
    }
    cout<<(cnt==a+b-1 ? "Possible" : "Impossible")<<endl;
}