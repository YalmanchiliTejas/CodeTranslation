#include<iostream>
using namespace std;
int main(){
    int m,A,year,n,type,tesuryo,a,b,max;
    double riritsu;
    cin>>m;
    for(int j=0;j<m;j++){
        cin>>A>>year>>n;
        max=0;
        for(int i=0;i<n;i++){
            cin>>type>>riritsu>>tesuryo;
            a=A;
            b=0;
            if(type==0){
                for(int k=0;k<year;k++){
                    b+=a*riritsu;
                    a-=tesuryo;
                }
                a+=b;
            }else{
                for(int k=0;k<year;k++){
                    a+=a*riritsu;
                    a-=tesuryo;
                }
            }
            if(max<a){
                max=a;   
            }
        }
        cout<<max<<endl;
    }
    return 0;
}