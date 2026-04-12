#include <iostream>
using namespace std;
 
int main(){
int gozen,gogo,total,shop;
        while(gozen!=0||gogo!=0){
        	total=0;
        	cin>>gozen>>gogo;
        	if(gozen+gogo==0)break;
        	if(total<gozen+gogo){
        		total=gozen+gogo;
        		shop=0;
        	}
        for(int i=1;i<5;i++){
                cin>>gozen>>gogo;
        	if(total<gozen+gogo){
        		total=gozen+gogo;
        		shop=i;
        	}
        }
        	if(shop==0)cout<<"A "<<total<<endl;
        	else if(shop==1)cout<<"B "<<total<<endl;
        	else if(shop==2)cout<<"C "<<total<<endl;
        	else if(shop==3)cout<<"D "<<total<<endl;
        	else cout<<"E "<<total<<endl;
        }
}