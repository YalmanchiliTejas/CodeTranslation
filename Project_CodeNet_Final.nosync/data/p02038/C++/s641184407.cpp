#include<iostream>
using namespace std;
int main(){
    int n; cin>>n;
    char c[100000];
    for(int i=0;i<n;++i) cin>>c[i];
    for(int i=1;i<n;++i){
	if(c[i-1]=='T'&&c[i]=='F') c[i]='F';
	else c[i]='T';
    }
    cout<<c[n-1]<<endl;
    return 0;
}
