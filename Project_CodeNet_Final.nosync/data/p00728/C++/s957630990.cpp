#include <iostream>
using namespace std;
int main(void){
    int n;
    while(1){
        cin >> n;
        if(n == 0){
            return 0;
        }
        int s_max = 0;
        int s_min = 1000;
        int sum = 0;
        int s;
        for( int i = 0; i < n ; ++i) {
            cin >> s;
            sum += s;
            s_max = max(s, s_max);
            s_min = min(s, s_min);
        }
        int ave = (sum-s_max-s_min)/(n-2);
        cout << ave << endl;
    }
}

