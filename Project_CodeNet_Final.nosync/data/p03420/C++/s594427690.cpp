#include <iostream>
using namespace std;

int main() {
long long n,k,c=0;
cin>>n>>k;
if(k==0){
    cout<<n*n<<endl;
    return 0;
}
for(int i=k+1;i<=n;i++){
//cout<<c<<endl;
    c+=(n/i)*(i-k);
    if((n%i-k+1>0)){
        c+=(n%i)-k+1;
    }
}
cout<<c<<endl;
	return 0;
}