#include<iostream>
#include<algorithm>

int main(){

    int count=1;
    int n;
    int h[20]={0};

    std::cin>>n;
   
    for(int i=0;i<n;i++){
        std::cin>>h[i];
      
    }

    for(int num=1;num<n;num++){ //今何番目を見てるか
        int high[20]={0};
    
        for(int i=0;i<n;i++){
            high[i]=h[i];
          
        }

        std::sort(high,high+num+1);

        if(high[num]==h[num]){
            count++;
           
        }
       
    }

    std::cout<<count<<std::endl;

    return 0;
}
