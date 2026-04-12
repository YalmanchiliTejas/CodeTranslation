#include<iostream>
 
using namespace std;
 
int main(){
 
    int m;
    int n;
    int money,nowmoney,year;
    int type,tesuu;
    int sumrisi;
    int ans;
    double risi;
 
    cin>>m;
 
    for(int i=0;i<m;i++){
        cin>>money;
        cin>>year;
        cin>>n;
        ans=-1;
        for(int j=0;j<n;j++){
            cin>>type>>risi>>tesuu;
            nowmoney=money;
            sumrisi=0;
            for(int k=0;k<year;k++){
                if(type==1){
                    nowmoney+=(nowmoney*risi)-tesuu;
                }
                else{
                    sumrisi+=(nowmoney*risi);
                    nowmoney-=tesuu;
                }
            }
            if(type==0) nowmoney+=sumrisi;
            if(ans<nowmoney) ans=nowmoney;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}