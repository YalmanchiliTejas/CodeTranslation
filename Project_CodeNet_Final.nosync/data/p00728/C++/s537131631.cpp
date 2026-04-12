#include <iostream>
using namespace std;
int main(void){
    int n; //審判の数

    while(true){
        int s[1010]; //各審判のつけた点数
        cin >> n;
        if(n == 0) break;

        for(int i = 0; i < n; i++)
            cin >> s[i];

        int max = 0, min = 1000; //点数の最小値、最大値
        for(int i = 0; i < n; i++){
            if(s[i] > max) max = s[i];
            if(s[i] < min) min = s[i];
        }

        int sum = 0; //最高点と最低値を除いた点数たちの和
        int mean; //最高点と最低値を除いた点数の平均値
        for(int i = 0; i < n; i++){
            sum += s[i];
        }
        mean = (sum - max - min) / (n - 2);

        cout << mean << endl;
    }
}

