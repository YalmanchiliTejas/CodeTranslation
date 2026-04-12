#include <iostream>
#include <string>

using namespace std;

int main() {
int a[7];

int n;
string c;
cin>>n;

while(n!=0){
	for(int j=1;j<7;j++){
	a[j]=j;
}
int sum=1;
for(int k=0;k<n;k++){
cin>>c;
if(c=="North"){
	int q=a[1];
	a[1]=a[2];
	a[2]=a[6];
	a[6]=a[5];
	a[5]=q;
}
if(c=="South"){
		int q=a[1];
	a[1]=a[5];
	a[5]=a[6];
	a[6]=a[2];
	a[2]=q;
}
if(c=="East"){
		int q=a[1];
	a[1]=a[4];
	a[4]=a[6];
	a[6]=a[3];
	a[3]=q;
}	
if(c=="West"){
		int q=a[1];
	a[1]=a[3];
	a[3]=a[6];
	a[6]=a[4];
	a[4]=q;
}	
if(c=="Right"){
		int q=a[2];
	a[2]=a[3];
	a[3]=a[5];
	a[5]=a[4];
	a[4]=q;
	
}
if(c=="Left"){
		int q=a[2];
	a[2]=a[4];
	a[4]=a[5];
	a[5]=a[3];
	a[3]=q;
}
	sum=sum+a[1];

}
cout<<sum<<endl;	
cin>>n;
}

	return 0;
}