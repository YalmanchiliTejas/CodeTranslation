#include <iostream>
using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b, a != 0 || b != 0){
        int max_shop = 0;
        int max = a + b;
        for(int i=1; i<5; i++){
            cin >> a >> b;
            if(max < a + b){
                max = a + b;
                max_shop = i;
            }
        }
        cout << (char)('A' + max_shop) << " " << max << endl;
    }
    return 0;
}