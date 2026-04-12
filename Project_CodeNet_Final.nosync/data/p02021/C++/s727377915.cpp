#include <iostream>
#include<math.h>
#include <algorithm>
using namespace std;
int n,a,f=1000,total;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;total+=a;
		if(f>(total-total%(i+1))/(i+1))f=(total-total%(i+1))/(i+1);
	}
	cout<<f<<endl;
    return 0;
}
