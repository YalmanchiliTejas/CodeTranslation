#include <iostream>
using namespace std;

int main(){
    int N; cin >> N; 
    int sum = 0;
    int Hotel[20];
    for(int i =0; i< N; i++){
        cin >> Hotel[i];
    }
    for(int i=0;i<N;i++){
        int highest;
        if(i==0){
            highest = Hotel[i];
            sum++;
        }else{
            if(highest <= Hotel[i]){
                sum++;
                highest = Hotel[i];
            }
        }
    }
    cout << sum;
    return 0;
}