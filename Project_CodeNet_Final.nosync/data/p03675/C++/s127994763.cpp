#include <iostream>
using namespace std;

int main() {
int n,a[200000],m;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
m=n-1;
while(m>=0){
    cout<<a[m]<<" ";
    m-=2;
}
if(m==-1){
    m=0;
}else{
    m=1;
}
while(m<=n-2){
    cout<<a[m]<<" ";
    m+=2;
}
cout<<endl;
	return 0;
}