#include <iostream>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int H[N];
    int sum=1;
    int max=1;
    for (int i=0 ; i<N ;i++){
       cin >> H[i];
       if (H[i]>=max){
           max=H[i];
           
       if (i!=0){
          sum=sum+1;}
       }
       }
       cout << sum <<endl;
       return 0;
}
