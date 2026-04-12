#include<iostream>
using namespace std;
int main(){
    int n;
    for(;;){
        cin>>n;
        if(n==0) break;
        int ds[]={1,2,3,5,4,6};
        int sum=ds[0];
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            if(s=="North"){
                int t=ds[0];
                ds[0]=ds[1];
                ds[1]=ds[5];
                ds[5]=ds[3];
                ds[3]=t;
            }else if(s=="South"){
                int t=ds[0];
                ds[0]=ds[3];
                ds[3]=ds[5];
                ds[5]=ds[1];
                ds[1]=t;
            }else if(s=="East"){
                int t=ds[0];
                ds[0]=ds[4];
                ds[4]=ds[5];
                ds[5]=ds[2];
                ds[2]=t;
            }else if(s=="West"){
                int t=ds[0];
                ds[0]=ds[2];
                ds[2]=ds[5];
                ds[5]=ds[4];
                ds[4]=t;
            }else if(s=="Right"){
                int t=ds[1];
                ds[1]=ds[2];
                ds[2]=ds[3];
                ds[3]=ds[4];
                ds[4]=t;
            }else if(s=="Left"){
                int t=ds[1];
                ds[1]=ds[4];
                ds[4]=ds[3];
                ds[3]=ds[2];
                ds[2]=t;
            }
            sum+=ds[0];
        }
        cout<<sum<<endl;
    }
}