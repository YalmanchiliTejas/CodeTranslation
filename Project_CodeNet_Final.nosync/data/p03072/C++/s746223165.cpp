#include<iostream>
using namespace std;

int main(void){
    int N,i,max,count=0;
    int mount[21]={0};
    cin >> N;
    for(i=1;i<=N;i++){
        cin >> mount[i];
    }

    for(i=1;i<=N;i++){
        if(i==1){
            count++;
            max = mount[1];
        }else if(mount[i]>=max){
            count++;
            max = mount[i];
        }
    }

    cout << count;

    return 0;
}