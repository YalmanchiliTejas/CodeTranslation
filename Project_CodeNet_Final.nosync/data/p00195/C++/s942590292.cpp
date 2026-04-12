
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void){
while(1){
	int a[9]={0};
	int flg=0;
	int m=0;
	int ed=0;
	for(int i=0;i<5;i++){
        int s;
        cin>>s;
        a[i]+=s;
        cin>>s;
        a[i]+=s;
        if(a[i]==0){
            ed=1;
            break;
        }
        if(a[i]>m)m=a[i],flg=i;

	}
	if(ed==1)break;
	switch(flg){
	case 0:cout<<"A ";break;
	case 1:cout<<"B ";break;
	case 2:cout<<"C ";break;
	case 3:cout<<"D ";break;
	case 4:cout<<"E ";break;

	};
	cout<<m<<endl;


}
	return 0;
}