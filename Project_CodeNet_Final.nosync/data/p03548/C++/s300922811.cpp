#include<iostream>
using namespace std;
int x,y,z,len,ans;
int main(){
	cin>>x>>y>>z;
    len+=z;
    while(len<=x){
		len+=y+z;
		ans++;
    }
    if(len>x) ans--;
    cout<<ans<<endl;
    return 0;
}