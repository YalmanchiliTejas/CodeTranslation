#include<iostream>
#include<string>
using namespace std;

int main(){
    int a[6],l = 1,n = 1;
    string m;
    while(1){
    a[0]=1;a[1]=3;a[2]=6;a[3]=4;a[4]=2;a[5]=5;
    cin>>n;
    if(n == 0)break;
	l = a[0];
    for(int i = 0 ; i < n ; i++){
        cin>>m;
        if(m == "North"){
            a[6]=a[0];a[0]=a[4];a[4]=a[2];a[2]=a[5];a[5]=a[6];
        }if(m == "East"){
            a[6]=a[0];a[0]=a[3];a[3]=a[2];a[2]=a[1];a[1]=a[6];
        }if(m == "West"){
            a[6]=a[0];a[0]=a[1];a[1]=a[2];a[2]=a[3];a[3]=a[6];
        }if(m == "South"){
            a[6]=a[0];a[0]=a[5];a[5]=a[2];a[2]=a[4];a[4]=a[6];
        }if(m == "Right"){
            a[6]=a[4];a[4]=a[1];a[1]=a[5];a[5]=a[3];a[3]=a[6];
        }if(m == "Left"){
            a[6]=a[4];a[4]=a[3];a[3]=a[5];a[5]=a[1];a[1]=a[6];
        }
        l = l +a[0];
    }
    cout<<l<<endl;
    }

    return 0;
}
