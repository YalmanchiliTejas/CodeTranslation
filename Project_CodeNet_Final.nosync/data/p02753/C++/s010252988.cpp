#include <iostream>
using namespace std;
int main(void){
    char a[3];
    for (int ik=0;ik<3;ik++){
        cin>>a[ik];
    }
    int ans=0;
    int sna=0;
    for (int i=0;i<3;i++){
        if(a[i]=='A')ans++;
        if(a[i]=='B')sna++;
    }
    if(ans==3||sna==3)cout<<"No"<<endl;
    else cout <<"Yes"<<endl;
    return 0;
    
}
