#include <iostream>
using namespace std;
int main(){
    int a, moneyF, yearL, vary, i1, i2, i3, s, moneyB1, moneyB2, risi1, risi2, moneyto, max;
    double per;
    i1 = 0;
    cin >> a;
    while(1){
        i1++;
        if(i1>a){break;}
        cin >> moneyF >> yearL >> vary;
        i2 = 0;
        max = 0;
        while(1){
            i2++;
            if(i2>vary){break;}
            cin >> s >> per >> moneyB1;
            i3 = 0;
            moneyB2 = moneyF;
            risi2 = 0;
            if(s==0){
                while(1){
                    i3++;
                    if(i3>yearL){break;}
                    risi1 = moneyB2 * per;
                    moneyB2 = moneyB2 - moneyB1;
                    risi2 = risi2 + risi1;
                }
            }
            else{
                while(1){
                    i3++;
                    if(i3>yearL){break;}
                    risi1 = moneyB2 * per;
                    moneyB2 = moneyB2 + risi1 - moneyB1;
                }
            }
            moneyto = moneyB2 + risi2;
            if(max<moneyto){max = moneyto;}
        }
        cout << max << endl;
        
        
    }
    return 0;

}