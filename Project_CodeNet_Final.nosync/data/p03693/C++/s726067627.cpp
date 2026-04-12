#include <iostream>
using namespace std;

/* int main(){
    int r,g,b;cin>>r>>g>>b;
    char rgb[3]={(char)r,(char)g,(char)b};
    cout<<rgb<<endl;
    int RGB=(int)rgb;
    cout<<RGB<<endl;
    if(RGB%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
    
} */

int main(){
    int r,g,b;
    cin>>r>>g>>b;
    if( (100*r+10*g+b)%4 == 0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}