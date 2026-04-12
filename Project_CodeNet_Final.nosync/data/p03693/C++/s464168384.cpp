#include<iostream>
#include<math.h>

using namespace std;

int main(void){

    int num[3];
    cin >> num[2] >> num[1] >> num[0];

    int sum = 0;
   
    for(int i = 2; i >= 0; i--){
        sum += num[i] * pow(10,i);
    }
   
    if(sum % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
   
    return 0;
}