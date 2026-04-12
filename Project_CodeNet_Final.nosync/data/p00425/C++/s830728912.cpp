#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(void){
	int n;
	while(1){
cin>>n;
if(n==0)break;
int u=5,m=1,d=2,r=3,l=4;
int temp,sum=1;
string w;
for(int i=0;i<n;i++){
cin>>w;
if(w=="North"){
temp=d;
d=7-m;
u=m;
m=temp;
sum+=m;
}else if(w=="East"){
temp=l;
l=7-m;
r=m;
m=temp;
sum+=m;
}else if(w=="South"){
temp=u;
u=7-m;
d=m;
m=temp;
sum+=m;
}else if(w=="West"){
temp=r;
r=7-m;
l=m;
m=temp;
sum+=m;
}else if(w=="Right"){
temp=d;
d=r;
r=u;
u=l;
l=temp;
sum+=m;
}else if(w=="Left"){
temp=d;
d=l;
l=u;
u=r;
r=temp;
sum+=m;
}

}
cout<<sum<<endl;
	}
	return 0;
}