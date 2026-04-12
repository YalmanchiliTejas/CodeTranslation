#include <iostream>
using namespace std;
int main(void){
    while(true){
        int max=0;
        char num;
        for(int i=0;i<5;i++){
            int a,b;
            cin >> a >> b;
            if(i==0 && (a|b)==0)return 0;
            if(max<(a+b)){
                max=a+b;
                num ='A'+i;
            }
        }
        cout << num << " " << max << endl;
    }
    return 0;
}

