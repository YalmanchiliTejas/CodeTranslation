#include<iostream>
using namespace std;

int main(void) {
    int max,min,num,average,avsum;
    do{
        cin>>num;
        int rawdata[1000] = {0};
        if(num == 0){
            return 0;
        }
        max = 0,min = 1000,avsum = num,average = 0;
        while(num > 0){
            num--;
            cin>>rawdata[num];
        }
        for(int i = 0; i < avsum;i++) {
            average += rawdata[i];
            if(max < rawdata[i]){
                max = rawdata[i];}
            if(min > rawdata[i]){
                min = rawdata[i];}
        }
        
        average -= max;
        average -= min;
        
        average /= (avsum - 2);
        cout<<average<<endl;
    }while(1);
    return 0;
}