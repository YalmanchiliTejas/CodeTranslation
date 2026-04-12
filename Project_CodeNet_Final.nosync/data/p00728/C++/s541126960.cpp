#include <iostream>

int main() {
    using namespace std;

    int c;
    int num;
    int max ;
    int min;
    int sum;
    int ans;
    while(true){
        max = 0;
        min = 1001;
        sum = 0;
        cin >> c;
        if(c == 0){
            break;
        }
        for(int i = 0; i < c; i++){
            cin >> num;
            if(num > max){
                max = num;
            }
            if(num < min){
                min = num;
            }
            sum += num;
        }
        ans = (sum - max - min)/(c-2);
        cout << ans << "\n";
    }
    return 0;
}
